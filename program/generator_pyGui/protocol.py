import serial
import sys
import time

from variables import *
from log_out import *

class Protocol():
    def __init__(self, log):
        ###--- Generator
        self.generator = { 'pulseWidth':0, # Value in seconds, only for interface
                        'pulseWidth_t':0, 'pulseWidth_mlt':'t',
                        'pulsePeriod':0, # Value in seconds, only for interface
                        'pulsePeriod_t':0, 'pulsePeriod_mlt':'t',
                        'pulse_psc':0,
                        'pulseN':0,
                        'packPeriod':0, # Value in seconds, only for interface
                        'pause':0, # Value in seconds, only for interface
                        'packPeriod_t':0, 'packPeriod_mlt':'t',
                        'pack_psc':0,
                        'state_generation':0 }

        self.log = log
        self.comport = serial.Serial()
        self.ports = []


    ###--- COM port
    def com_open(self, port):
        # Return true if has been error
        # Open COM port
        try:
            self.comport.baudrate = 115200
            self.comport.port = port
            self.comport.timeout = 0.1
            self.comport.close()

            message = "COM port created."
            self.log.log_out_ivent(message)
        except (OSError, serial.SerialException):
            message = "COM port error."
            self.log.log_out_ivent(message)
            #print(message)
            return True
        
        # Open
        try:
            self.comport.open()

            message = "Opened COM port."
            self.log.log_out_ivent(message)
            #print(message)
            return False
        except (OSError, serial.SerialException):
            message = "Can't open COM port."
            self.log.log_out(message, 'both')
            #print(message)
            return True

    def com_close(self):
        # Return true if has been error
        # Close
        try:
            self.comport.close()

            message = "Closed COM port."
            self.log.log_out_ivent(message)
            return False
        except (OSError, serial.SerialException):
            message = "Can't close COM port."
            self.log.log_out(message, 'both')
            #print(message)
            return True

    def com_send(self, data, source):
        # Source - source of sending data (just function name)
        try:
            self.comport.write(data)

            message = "Write in COM port. Source: " + source
            self.log.log_out(message, 'file')
            message = "Data: " + str(data)
            self.log.log_out(message, 'file')
        except (OSError, serial.SerialException):
            message = "Can't write in COM port. Source: " + source
            self.log.log_out(message, 'file')
            message = "Data: " + str(data)
            self.log.log_out(message, 'file')
            #print(message)

    def com_read(self, length, source):
        # Source - source of receiving data (just function name)
        try:
            received_data = self.comport.read(length)

            received_data_int = []
            for byte in received_data:
                received_data_int.append(int(byte))
            message = "Read from COM port. Source: " + source
            self.log.log_out(message, 'file')
            message = "Data: " + str(received_data_int)
            self.log.log_out(message, 'file')

            return received_data
        except (OSError, serial.SerialException):
            message = "Can't read from COM port. Source: " + source
            self.log.log_out(message, 'file')
            #print(message)

    def comport_refresh(self):
        portsall = serial.tools.list_ports.comports()
        self.ports = []
        for port in portsall:
            self.ports.append(port.device)


    ###--- Check sum
    def get_SUM(self, data):
        summm = 0 # result
        it = 0
        
        while it < (data[uart_n_quantity] - uart_n_sum):
            summm += int(data[it])
            it += 1

        summm += uart_com_stop

        return (summm & 0xFF)

    def get_XOR(self, data):
        xorrr = 0 # result
        it = 0
        
        while it < (data[uart_n_quantity] - uart_n_xor):
            xorrr ^= int(data[it])
            it += 1

        xorrr ^= uart_com_stop

        return (xorrr & 0xFF)


    ###--- functions
    def search_arr_psc_crr(self, time, duty):
        target_f = 1 / time
        arr_max = 65535
        psc_max = 65535
        max_error = 10
        results = []

        flag_first_solution = False
        for psc in range(0, psc_max + 1):
            value = (MCU_FREQ / (target_f * (psc + 1))) - 1
            if((MCU_FREQ % (psc + 1) == 0) & (value <= arr_max)):
                for arr in range(0, arr_max + 1):
                    result = (arr + 1) * (psc + 1)
                    error = abs((1 - ((MCU_FREQ / result) / target_f)) * 100)
                    if(error <= max_error):
                        #Debug
                        #print("Error: " + str(error))
                        #Debug
                        ccr = int(arr / (100.0 / duty) - 1)
                        results.append({'psc':psc, 'arr':arr, 'ccr':ccr, 'error':error})
                        if(error <= ERROR_DELTA_LOG):
                            flag_first_solution = True
                            #Debug
                            #print("flag_first_solution, error: " + str(error))
                            #Debug
                            break
            if flag_first_solution:
                break

        results_sorted = sorted(results, key = lambda i: (i['error']))

        #Debug
        #if(results_sorted[0]['error'] != 0):
            #print("Error: " + str(results_sorted[0]['error']))
        #Debug

        # Change if values == 0
        if(results_sorted[0]['arr'] == 0):
            results_sorted[0]['arr'] = 1
        if(results_sorted[0]['ccr'] == 0):
            results_sorted[0]['ccr'] = 1

        return results_sorted[0]

    def get_valueDec(self, value, measure):
        if(measure == uart_measure_t):
            value /= MCU_FREQ
        elif(measure == uart_measure_n):
            value /= 1000000000
        elif(measure == uart_measure_u):
            value /= 1000000
        elif(measure == uart_measure_m):
            value /= 1000
        elif(measure == uart_measure_s):
            pass
        else:
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        return value

    def get_valueAndPsc(self, value, duty, measure):
        value = self.get_valueDec(value, measure)
        values = self.search_arr_psc_crr(value, duty)

        return values

    def get_tickFromValue(self, value, measure):
        tick = 1 / MCU_FREQ
        if(measure == uart_measure_t):
            pass
        elif(measure == uart_measure_n):
            value /= tick * 1000000000
        elif(measure == uart_measure_u):
            value /= tick * 1000000
        elif(measure == uart_measure_m):
            value /= tick * 1000
        elif(measure == uart_measure_s):
            value /= tick * 1
        else:
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        return int(value)

    def get_valueFromTick(self, tick, psc, measure):
        # Return 'value' and result 'measure' for better view
        one_tick = 1 / MCU_FREQ
        measure_mass = ['t', 'n', 'u', 'm', 's']
        measure_counter = 0

        value = one_tick * (psc + 1) * (tick + 2) # With +2, value in generator == time from oscilloscope (check on psc == 0)

        if(measure == uart_measure_t):
            value *= 1000000000
            measure_counter = 0
        elif(measure == uart_measure_n):
            value *= 1000000000
            measure_counter = 1
        elif(measure == uart_measure_u):
            value *= 1000000
            measure_counter = 2
        elif(measure == uart_measure_m):
            value *= 1000
            measure_counter = 3
        elif(measure == uart_measure_s):
            measure_counter = 4
        else:
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        while(int(value) < 10):
            value *= 1000
            measure_counter -= 1
            if(measure_counter <= 1):
                break

        return {'value':int(value), 'measure':measure_mass[measure_counter], 'counter':measure_counter}

    def get_modifValue(self, value):
        # Return 'value' and result 'measure' for better view
        one_tick = 1 / MCU_FREQ
        measure_mass = ['t', 'n', 'u', 'm', 's']
        measure_counter = 4

        while(int(value) < 10):
            value *= 1000
            measure_counter -= 1
            if(measure_counter <= 1):
                break

        return {'value':round(value, MAX_DECIMAL), 'measure':measure_mass[measure_counter], 'counter':measure_counter}

    def get_measureChar(self, measure):
        result = 0
        if(measure == uart_measure_t):
            result = 't'
        elif(measure == uart_measure_n):
            result = 'n'
        elif(measure == uart_measure_u):
            result = 'u'
        elif(measure == uart_measure_m):
            result = 'm'
        elif(measure == uart_measure_s):
            result = 's'
        else:
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        return result

    def get_measureCounter(self, measure):
        result = 0
        if(measure == 't'):
            result = 0
        elif(measure == 'n'):
            result = 1
        elif(measure == 'u'):
            result = 2
        elif(measure == 'm'):
            result = 3
        elif(measure == 's'):
            result = 4
        else:
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        return result

    def get_measureHex(self, measure):
        result = 0
        if(measure == 't'):
            result = uart_measure_t
        elif(measure == 'n'):
            result = uart_measure_n
        elif(measure == 'u'):
            result = uart_measure_u
        elif(measure == 'm'):
            result = uart_measure_m
        elif(measure == 's'):
            result = uart_measure_s
        else:
            result = uart_error_prefix
            message = "Invalid prefix value."
            self.log.log_out(message, 'both')

        return result


    def check_get_impulse_parameters(self, errors):
        # Return True if error
        result = False
        message = ""
        for key, error in errors.items():
            if(error != uart_error_no):
                result = True
                if(error == uart_error_xor):
                    message = "In " + key + "() error: wrong XOR."
                elif(error == uart_error_sum):
                    message = "In " + key + "() error: wrong SUM."
                elif(error == uart_error_time):
                    message = "In " + key + "() error: long time waiting."
                elif(error == uart_error_command):
                    message = "In " + key + "() error: wrong command."
                else:
                    message = "In " + key + "() error: wrong response."
                self.log.log_out(message, 'file')

        if message:
            message = "Error while getting parameters from generator."
            self.log.log_out(message, 'both')
        else:
            message = ("No error in received data.")
            self.log.log_out(message, 'file')

        return result


    ###--- Send packages
    def send_pulseWidth(self, pulseWidth, measure):
        # Log try to send
        message = "Send pulse width."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_pulseWidth), int(uart_com_send_pulseWidth), 
                int(pulseWidth >> 8), int(pulseWidth & 0xFF), int(measure), int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_pulseWidth - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_pulseWidth - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send pulse width."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_pulseWidth(" + str(pulseWidth) + ", " + str(measure) + ").")
        # Log sended
        message = "Sended pulse width."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_pulseWidth + 1, "send_pulseWidth(" + str(pulseWidth) + ", " + str(measure) + ") ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_pulseWidth':self.check_response()}
        self.check_get_impulse_parameters(error)
        
        #Debug
        # #print("Send pulseWidth in generator: ")
        # #print(data)
        # data_hex = []
        # for byte in data:
        #     data_hex.append(hex(byte))
        # #print(data_hex)
        #Debug

    def send_pulsePeriod(self, pulsePeriod, pulsePeriod_psc, measure):
        # Log try to send
        message = "Send pulse period."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_period), int(uart_com_send_pulsePeriod), 
                int(pulsePeriod >> 8), int(pulsePeriod & 0xFF), int(measure), 
                int(pulsePeriod_psc >> 8), int(pulsePeriod_psc & 0xFF), int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_period - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_period - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send pulse period."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_pulsePeriod(" + str(pulsePeriod) + ", " + str(pulsePeriod_psc) + ", " + str(measure) + ").")
        # Log sended
        message = "Sended pulse period."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_period + 1, "send_pulsePeriod(" + str(pulsePeriod) + ", " + str(pulsePeriod_psc) + ", " + str(measure) + ") ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_pulsePeriod':self.check_response()}
        self.check_get_impulse_parameters(error)

    def send_pulsePeriodDuty(self, pulsePeriod, duty, measure):
        # Log try to send
        message = "Send pulse pulse parameters."
        self.log.log_out_ivent(message)
        # Value preparation
        values = self.get_valueAndPsc(pulsePeriod, duty, measure)
        pulseWidth = values['ccr']
        pulsePeriod = values['arr']
        pulsePeriod_psc = values['psc']

        # Log if error
        if(values['error'] != 0):
            if(values['error'] > ERROR_DELTA_LOG):
                message = "Could not match PSC and ARR to set the exact value, delta: " + str(round(values['error'], int(1 / ERROR_DELTA_LOG)))
                self.log.log_out(message, 'gui')
            message = "Could not match PSC and ARR to set the exact value, delta: " + str(values['error'])
            self.log.log_out_ivent(message)

        # Send period
        self.send_pulsePeriod(pulsePeriod, pulsePeriod_psc, measure)
        # Send width
        self.send_pulseWidth(pulseWidth, measure)

        # Log sended values
        message = "Sended pulse parameters."
        self.log.log_out(message, 'file')

    def send_packPeriod(self, packPeriod, measure):
        # Log try to send
        message = "Send pack period."
        self.log.log_out_ivent(message)
        # Value preparation
        values = self.get_valueAndPsc(packPeriod, packPeriod, measure) # No need in duty
        packPeriod = values['arr']
        packPeriod_psc = values['psc']

        # Log send values
        message = "Pack parameters: " + str(values)
        self.log.log_out(message, 'file')

        # Log if error
        if(values['error'] != 0):
            if(values['error'] > ERROR_DELTA_LOG):
                message = "Could not match PSC and ARR to set the exact value, delta: " + str(round(values['error'], int(1 / ERROR_DELTA_LOG)))
                self.log.log_out(message, 'gui')
            message = "Could not match PSC and ARR to set the exact value, delta: " + str(values['error'])
            self.log.log_out_ivent(message)

        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_period), int(uart_com_send_packPeriod), 
                int(packPeriod >> 8), int(packPeriod & 0xFF), int(measure), 
                int(packPeriod_psc >> 8), int(packPeriod_psc & 0xFF), int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_period - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_period - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send pack period."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_packPeriod(" + str(packPeriod) + ", " + str(measure) + ").")
        # Log sended
        message = "Sended pack period."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_period + 1, "send_packPeriod(" + str(packPeriod) + ", " + str(measure) + ") ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_packPeriod':self.check_response()}
        self.check_get_impulse_parameters(error)

    def send_pulseN(self, pulseN):
        # Log try to send
        message = "Send number of pulses in pack."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_pulseN), int(uart_com_send_pulseN), 
                int(pulseN >> 8), int(pulseN & 0xFF), int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_pulseN - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_pulseN - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send number of pulses in pack."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_pulseN(" + str(pulseN) + ").")
        # Log sended
        message = "Sended number of pulses in pack."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_pulseN + 1, "send_pulseN(" + str(pulseN) + ") ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_pulseN':self.check_response()}
        self.check_get_impulse_parameters(error)

    def send_setParameters(self):
        # Log try to send
        message = "Send set parameters."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_setParameters), int(uart_com_set_parameters), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_setParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_setParameters - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send set parameters."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_setParameters().")
        # Log sended
        message = "Sended set parameters."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_setParameters + 1, "send_setParameters() ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_setParameters':self.check_response()}
        self.check_get_impulse_parameters(error)

    def send_set_generatorImpulseOff(self):
        # Log try to send
        message = "Send generator off."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_setParameters), int(uart_com_off), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_setParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_setParameters - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send generator off."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_set_generatorImpulseOff().")
        # Log sended
        message = "Sended generator off."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_setParameters + 1, "send_set_generatorImpulseOff() ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_set_generatorImpulseOff':self.check_response()}
        self.check_get_impulse_parameters(error)

    def send_set_generatorImpulseOn(self):
        # Log try to send
        message = "Send generator on."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_setParameters), int(uart_com_on), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_setParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_setParameters - uart_n_xor] = self.get_XOR(data)
        # Log send
        message = "Start send generator on."
        self.log.log_out(message, 'file')
        # Send in generator
        self.com_send(data, "send_set_generatorImpulseOff().")
        # Log sended
        message = "Sended generator on."
        self.log.log_out(message, 'file')

        received_data = self.com_read(uart_pack_setParameters + 1, "send_set_generatorImpulseOn() ----- Clear COM buffer.") # Clear buff
        # Log if error
        error = {'send_set_generatorImpulseOn':self.check_response()}
        self.check_get_impulse_parameters(error)

    def check_response(self):
        message = "Check response from generator."
        self.log.log_out_ivent(message)
        received_data = self.com_read(uart_pack_response + 1, "check_response().") # +1, because check_sum
        #Debug
        # #print("check_response(): ")
        # data_hex = []
        # for byte in received_data:
        #     data_hex.append(hex(byte))
        # #print(data_hex)
        #Debug

        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_response - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_response - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # Check response
        response = received_data[uart_n_response]
        if(response == uart_error_no):
            return uart_error_no
        elif(response == uart_error_xor):
            return uart_error_xor
        elif(response == uart_error_sum):
            return uart_error_sum
        elif(response == uart_error_time):
            return uart_error_time
        elif(response == uart_error_command):
            return uart_error_command
        elif(response == uart_error_empty):
            return uart_error_empty
        else:
            return response


    ###--- Get value
    def get_pulseWidth(self): # Before this, need get pulsePeriod for get psc
        # Log get_pulseWidth
        message = "Get pulseWidth from generator."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_getParameters), int(uart_com_get_pulseWidth), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_getParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_getParameters - uart_n_xor] = self.get_XOR(data)
        # Send in generator
        self.com_send(data, "get_pulseWidth().")
        received_data = self.com_read(uart_pack_getParameters + 1, "get_pulseWidth() ----- Clear COM buffer.") # Clear buff
        #Debug
        # #print("get_pulseWidth(): ")
        # data_hex = []
        # for byte in received_data:
        #     data_hex.append(hex(byte))
        # #print(data_hex)
        #Debug
        
        # Log receive
        message = "Start receive data from generator."
        self.log.log_out(message, 'file')
        # Read from generator
        received_data = self.com_read(uart_pack_pulseWidth + 1, "get_pulseWidth().")
        # Log received
        message = "Received data from generator."
        self.log.log_out(message, 'file')
        
        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_pulseWidth - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_pulseWidth - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # Value
        value = int(received_data[uart_n_value] << 8) + int(received_data[uart_n_value + 1])
        measure = received_data[uart_n_measure]
        psc = self.generator['pulse_psc']

        self.generator['pulseWidth_t'] = round(value, MAX_DECIMAL)
        self.generator['pulseWidth_mlt'] = measure
        return uart_error_no

    def get_pulsePeriod(self):
        # Log get_pulsePeriod
        message = "Get pulsePeriod from generator."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_getParameters), int(uart_com_get_pulsePeriod), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_getParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_getParameters - uart_n_xor] = self.get_XOR(data)
        # Send in generator
        self.com_send(data, "get_pulsePeriod().")
        received_data = self.com_read(uart_pack_getParameters + 1, "get_pulsePeriod() ----- Clear COM buffer.") # Clear buff
        
        # Log receive
        message = "Start receive data from generator."
        self.log.log_out(message, 'file')
        # Read from generator
        received_data = self.com_read(uart_pack_period + 1, "get_pulsePeriod().")
        # Log received
        message = "Received data from generator."
        self.log.log_out(message, 'file')
        
        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_period - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_period - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # Value
        value = int(received_data[uart_n_value] << 8) + int(received_data[uart_n_value + 1])
        measure = received_data[uart_n_measure]
        psc = int(received_data[uart_n_presscale] << 8) + int(received_data[uart_n_presscale + 1])

        self.generator['pulsePeriod_t'] = round(value, MAX_DECIMAL)
        self.generator['pulsePeriod_mlt'] = measure
        self.generator['pulse_psc'] = psc
        return uart_error_no

    def get_packPeriod(self):
        # Log get_packPeriod
        message = "Get packPeriod from generator."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_getParameters), int(uart_com_get_packPeriod), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_getParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_getParameters - uart_n_xor] = self.get_XOR(data)
        # Send in generator
        self.com_send(data, "get_packPeriod().")
        received_data = self.com_read(uart_pack_getParameters + 1, "get_packPeriod() ----- Clear COM buffer.") # Clear buff
        
        # Log receive
        message = "Start receive data from generator."
        self.log.log_out(message, 'file')
        # Read from generator
        received_data = self.com_read(uart_pack_period + 1, "get_packPeriod().")
        # Log received
        message = "Received data from generator."
        self.log.log_out(message, 'file')
        
        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_period - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_period - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # Value
        value = int(received_data[uart_n_value] << 8) + int(received_data[uart_n_value + 1])
        measure = received_data[uart_n_measure]
        psc = int(received_data[uart_n_presscale] << 8) + int(received_data[uart_n_presscale + 1])

        self.generator['packPeriod_t'] = round(value, MAX_DECIMAL)
        self.generator['packPeriod_mlt'] = measure
        self.generator['pack_psc'] = psc
        return uart_error_no

    def get_pulseN(self):
        # Log get_pulseN
        message = "Get pulseN from generator."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_getParameters), int(uart_com_get_pulseN), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_getParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_getParameters - uart_n_xor] = self.get_XOR(data)
        # Send in generator
        self.com_send(data, "get_pulseN().")
        received_data = self.com_read(uart_pack_getParameters + 1, "get_pulseN() ----- Clear COM buffer.") # Clear buff
        
        # Log receive
        message = "Start receive data from generator."
        self.log.log_out(message, 'file')
        # Read from generator
        received_data = self.com_read(uart_pack_pulseN + 1, "get_pulseN().")
        # Log received
        message = "Received data from generator."
        self.log.log_out(message, 'file')
        
        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_pulseN - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_pulseN - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # Value
        value = int(received_data[uart_n_value] << 8) + int(received_data[uart_n_value + 1])

        self.generator['pulseN'] = value
        return uart_error_no

    def get_impulse_generator_state(self):
        # Log get_impulse_generator_state
        message = "Get state_generation from generator."
        self.log.log_out_ivent(message)
        # Package preparation
        data = [ int(uart_com_start), int(uart_pack_getParameters), int(uart_com_generation), 
                int(0x00), int(0x00), int(uart_com_stop) ]
        data[uart_pack_getParameters - uart_n_sum] = self.get_SUM(data)
        data[uart_pack_getParameters - uart_n_xor] = self.get_XOR(data)
        # Send in generator
        self.com_send(data, "get_impulse_generator_state().")
        received_data = self.com_read(uart_pack_getParameters + 1, "get_impulse_generator_state() ----- Clear COM buffer.") # Clear buff
        
        # Log receive
        message = "Start receive data from generator."
        self.log.log_out(message, 'file')
        # Read from generator
        received_data = self.com_read(uart_pack_response + 1, "get_impulse_generator_state().")
        # Log received
        message = "Received data from generator."
        self.log.log_out(message, 'file')
        
        # Check SUM
        if received_data:
            summm = self.get_SUM(received_data)
            if(summm != received_data[uart_pack_response - uart_n_sum]):
                #print("Wrong SUM")
                return uart_error_sum
        else:
            #print("Empty received data")
            return uart_error_empty

        # Check XOR
        xorrr = self.get_XOR(received_data)
        if(xorrr != received_data[uart_pack_response - uart_n_xor]):
            #print("Wrong XOR")
            return uart_error_xor

        # State
        state = int(received_data[uart_n_value])
        self.generator['state_generation'] = state

        return uart_error_no

    def get_impulse_parameters(self):
        # Log get all parameters from generator
        message = ("Get all generator parameters.")
        self.log.log_out_ivent(message)
        # Return list of error for every get
        error_pulseWidth = self.get_pulseWidth()
        error_pulsePeriod = self.get_pulsePeriod()
        error_pulseN = self.get_pulseN()
        error_packPeriod = self.get_packPeriod()
        error_generation = self.get_impulse_generator_state()
        # Log received
        message = "Received all parameters from generator."
        self.log.log_out(message, 'file')
        # Parameters
        message = "Generator parameters:"
        self.log.log_out(message, 'file')
        message = str(self.generator)
        self.log.log_out(message, 'file')

        errors = {'get_pulseWidth':error_pulseWidth, 'get_pulsePeriod':error_pulsePeriod, 
                'get_pulseN':error_pulseN, 'get_packPeriod':error_packPeriod,
                'get_impulse_generator_state':error_generation}

        return errors

