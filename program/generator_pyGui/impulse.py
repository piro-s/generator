import tkinter as tk
from tkinter import ttk
from tkinter import simpledialog

from log_out import *
from protocol import *
from quick_sets import *


class Impulse():
    def __init__(self, tab, log, protocol):
        self.frame_image = ttk.Frame(tab)
        self.frame_data = ttk.Frame(tab)
        self.log = log
        self.protocol = protocol
        self.quick_sets = Quick_sets()
        self.quick_sets.sets_load_file()


        ###--- r&c
        self.column_log = log.column
        self.column_title = self.column_log
        self.column_current = self.column_title
        self.column_set_text = self.column_current + 3
        self.column_set_value = self.column_set_text + 1
        self.column_set_measure = self.column_set_value + 1
        self.column_set_send = self.column_set_measure + 1
        self.column_divider = self.column_set_send + 1
        self.column_quick = self.column_divider + 1
        self.row_log = log.row
        self.row_title = self.row_log + 7
        self.row_pulseWidth = self.row_title + 1
        self.row_pulsePeriod = self.row_pulseWidth + 1
        self.row_packPeriod = self.row_pulsePeriod + 2
        self.row_pulseN = self.row_packPeriod + 1
        self.row_pause = self.row_pulseN + 1
        self.row_last = self.row_pause + 1
        self.row_divider = self.row_last + 1


        ###--- images
        self.gui_scheme = tk.PhotoImage(file='gui_scheme.gif')
        self.lbl_gui_scheme = tk.Label(self.frame_image, image=self.gui_scheme)
        self.lbl_gui_scheme.grid(column=0, row=0)
        self.gui_devider = tk.PhotoImage(file='gui_devider.gif')
        self.lbl_gui_devider = tk.Label(self.frame_data, image=self.gui_devider)
        self.lbl_gui_devider.grid(column=self.column_set_send, row=self.row_pulsePeriod + 1)


        ###--- current
        ########################################################################
        ###--- lables
        self.lbl_pulseWidth_current = tk.Label(self.frame_data, text="Current:")
        self.lbl_pulseWidth_current.grid(column=self.column_title, row=self.row_title, sticky='w')

        self.lbl_pulseWidth_current = tk.Label(self.frame_data, text="Pulse width: ")
        self.lbl_pulseWidth_current.grid(column=self.column_current, row=self.row_pulseWidth, sticky='w')
        self.lbl_pulseWidth_current_value = tk.Label(self.frame_data, text="-----")
        self.lbl_pulseWidth_current_value.grid(column=self.column_current + 1, row=self.row_pulseWidth, sticky='e')
        self.lbl_pulseWidth_current_measure = tk.Label(self.frame_data, text="-")
        self.lbl_pulseWidth_current_measure.grid(column=self.column_current + 2, row=self.row_pulseWidth, sticky='e')

        self.lbl_pulsePeriod_current = tk.Label(self.frame_data, text="Pulse period: ")
        self.lbl_pulsePeriod_current.grid(column=self.column_current, row=self.row_pulsePeriod, sticky='w')
        self.lbl_pulsePeriod_current_value = tk.Label(self.frame_data, text="-----")
        self.lbl_pulsePeriod_current_value.grid(column=self.column_current + 1, row=self.row_pulsePeriod, sticky='e')
        self.lbl_pulsePeriod_current_measure = tk.Label(self.frame_data, text="-")
        self.lbl_pulsePeriod_current_measure.grid(column=self.column_current + 2, row=self.row_pulsePeriod, sticky='e')

        self.lbl_packPeriod_current = tk.Label(self.frame_data, text="Pack period: ")
        self.lbl_packPeriod_current.grid(column=self.column_current, row=self.row_packPeriod, sticky='w')
        self.lbl_packPeriod_current_value = tk.Label(self.frame_data, text="-----")
        self.lbl_packPeriod_current_value.grid(column=self.column_current + 1, row=self.row_packPeriod, sticky='e')
        self.lbl_packPeriod_current_measure = tk.Label(self.frame_data, text="-")
        self.lbl_packPeriod_current_measure.grid(column=self.column_current + 2, row=self.row_packPeriod, sticky='e')

        self.lbl_pulseN_current = tk.Label(self.frame_data, text="Pulses in pack: ")
        self.lbl_pulseN_current.grid(column=self.column_current, row=self.row_pulseN, sticky='w')
        self.lbl_pulseN_current_value = tk.Label(self.frame_data, text="-----")
        self.lbl_pulseN_current_value.grid(column=self.column_current + 1, row=self.row_pulseN, sticky='e')

        self.lbl_pause_current = tk.Label(self.frame_data, text="Pause: ")
        self.lbl_pause_current.grid(column=self.column_current, row=self.row_pause, sticky='w')
        self.lbl_pause_current_value = tk.Label(self.frame_data, text="-----")
        self.lbl_pause_current_value.grid(column=self.column_current + 1, row=self.row_pause, sticky='e')
        self.lbl_pause_current_measure = tk.Label(self.frame_data, text="-")
        self.lbl_pause_current_measure.grid(column=self.column_current + 2, row=self.row_pause, sticky='e')


        ###--- deviders
        self.lbl_log_devider = tk.Label(self.frame_data, text="{: <5}".format('')) # Empty row for better view
        self.lbl_log_devider.grid(column=self.column_log, row=self.row_divider)
        self.lbl_set_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_set_devider.grid(column=self.column_divider, row=self.row_title)
        self.lbl_pulseWidth_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_pulseWidth_devider.grid(column=self.column_divider, row=self.row_pulseWidth)
        self.lbl_pulsePeriod_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_pulsePeriod_devider.grid(column=self.column_divider, row=self.row_pulsePeriod)
        self.lbl_packPeriod_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_packPeriod_devider.grid(column=self.column_divider, row=self.row_packPeriod)
        self.lbl_pulseN_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_pulseN_devider.grid(column=self.column_divider, row=self.row_pulseN)
        self.lbl_parameters_devider = tk.Label(self.frame_data, text="     ")
        self.lbl_parameters_devider.grid(column=self.column_divider, row=self.row_last)


        ###--- quick setup
        ########################################################################
        self.lbl_quick_setup = tk.Label(self.frame_data, text="Quick setup: ")
        self.lbl_quick_setup.grid(column=self.column_quick, row=self.row_title, sticky='w')
        self.lbl_quick_name = tk.Label(self.frame_data, text="Name: ")
        self.lbl_quick_name.grid(column=self.column_quick, row=self.row_packPeriod, sticky='w')

        self.cmb_quick_sets = ttk.Combobox(self.frame_data, width=15)
        self.quick_sets_list = []
        for name in self.quick_sets.sets['quick_sets']:
            self.quick_sets_list.append(name['name'])
        self.cmb_quick_sets['values'] = self.quick_sets_list
        self.cmb_quick_sets.current(0) # Default option
        self.cmb_quick_sets.grid(column=self.column_quick, row=self.row_pulseWidth, sticky='w')

        self.ent_quick_name = tk.Entry(self.frame_data, width=18)
        self.ent_quick_name.grid(column=self.column_quick, row=self.row_pulseN, sticky='w')


        self.btn_quick_load = tk.Button(self.frame_data, text="Load", command=self.quick_set_load)
        self.btn_quick_load.grid(column=self.column_quick + 1, row=self.row_pulseWidth, sticky='w')
        self.btn_quick_remove = tk.Button(self.frame_data, text="Remove", command=self.quick_set_remove)
        self.btn_quick_remove.grid(column=self.column_quick + 2, row=self.row_pulseWidth, sticky='w')
        self.btn_quick_setup = tk.Button(self.frame_data, text="Setup", command=self.quick_set_set)
        self.btn_quick_setup.grid(column=self.column_quick, row=self.row_pulsePeriod, sticky='w')
        self.btn_quick_save = tk.Button(self.frame_data, text="Save", command=self.quick_set_save)
        self.btn_quick_save.grid(column=self.column_quick + 1, row=self.row_pulseN, sticky='w')



        ###--- buttons
        self.btn_getParameters_current = tk.Button(self.frame_data, text="Get parameters", command=self.get_impulse_parameters)
        self.btn_getParameters_current.grid(column=self.column_title, row=self.row_last, sticky='w')
        ########################################################################

        ###--- set
        ########################################################################
        ###--- lables
        self.lbl_set = tk.Label(self.frame_data, text="Set:")
        self.lbl_set.grid(column=self.column_set_text, row=self.row_title, sticky='w')
        self.lbl_pulseWidth = tk.Label(self.frame_data, text="Pulse width: ")
        self.lbl_pulseWidth.grid(column=self.column_set_text, row=self.row_pulseWidth, sticky='w')
        self.lbl_pulsePeriod = tk.Label(self.frame_data, text="Pulse period: ")
        self.lbl_pulsePeriod.grid(column=self.column_set_text, row=self.row_pulsePeriod, sticky='w')
        self.lbl_packPeriod = tk.Label(self.frame_data, text="Pack period: ")
        self.lbl_packPeriod.grid(column=self.column_set_text, row=self.row_packPeriod, sticky='w')
        self.lbl_pulseN = tk.Label(self.frame_data, text="Pulses in pack: ")
        self.lbl_pulseN.grid(column=self.column_set_text, row=self.row_pulseN, sticky='w')
        self.lbl_generation = tk.Label(self.frame_data, text="Generator: ")
        self.lbl_generation.grid(column=self.column_set_text, row=self.row_last, sticky='w')
        self.lbl_generation_value = tk.Label(self.frame_data, text="off")
        self.lbl_generation_value.grid(column=self.column_set_value, row=self.row_last, sticky='w')


        ###--- variables
        self.var_pulseWidth = tk.StringVar(self.frame_data)
        self.var_pulseWidth.set("1")
        self.var_pulsePeriod = tk.StringVar(self.frame_data)
        self.var_pulsePeriod.set("1")
        self.var_packPeriod = tk.StringVar(self.frame_data)
        self.var_packPeriod.set("1")
        self.var_pulseN = tk.StringVar(self.frame_data)
        self.var_pulseN.set("1")


        ###--- spinboxes
        self.spn_pulseWidth = tk.Spinbox(self.frame_data, from_=1, to=MAX_SET_VALUE, width=5, textvariable=self.var_pulseWidth)
        self.spn_pulseWidth.grid(column=self.column_set_value, row=self.row_pulseWidth)
        self.spn_pulsePeriod = tk.Spinbox(self.frame_data, from_=1, to=MAX_SET_VALUE, width=5, textvariable=self.var_pulsePeriod)
        self.spn_pulsePeriod.grid(column=self.column_set_value, row=self.row_pulsePeriod)
        self.spn_packPeriod = tk.Spinbox(self.frame_data, from_=1, to=MAX_SET_VALUE, width=5, textvariable=self.var_packPeriod)
        self.spn_packPeriod.grid(column=self.column_set_value, row=self.row_packPeriod)
        self.spn_pulseN = tk.Spinbox(self.frame_data, from_=1, to=MAX_SET_VALUE, width=5, textvariable=self.var_pulseN)
        self.spn_pulseN.grid(column=self.column_set_value, row=self.row_pulseN)


        ###--- comboboxes
        self.cmb_pulseWidth = ttk.Combobox(self.frame_data, width=5)
        self.cmb_pulseWidth['values'] = ('t', 'n', 'u', 'm', 's')
        self.cmb_pulseWidth.current(2) # Default option
        self.cmb_pulseWidth.grid(column=self.column_set_measure, row=self.row_pulseWidth)
        self.cmb_pulsePeriod = ttk.Combobox(self.frame_data, width=5)
        self.cmb_pulsePeriod['values'] = ('t', 'n', 'u', 'm', 's')
        self.cmb_pulsePeriod.current(2) # Default option
        self.cmb_pulsePeriod.grid(column=self.column_set_measure, row=self.row_pulsePeriod)
        self.cmb_packPeriod = ttk.Combobox(self.frame_data, width=5)
        self.cmb_packPeriod['values'] = ('t', 'n', 'u', 'm', 's')
        self.cmb_packPeriod.current(2) # Default option
        self.cmb_packPeriod.grid(column=self.column_set_measure, row=self.row_packPeriod)


        ###--- buttons
        #self.btn_pulseWidth = tk.Button(self.frame_data, text="Send", command=send_pulseWidth)
        #self.btn_pulseWidth.grid(column=self.column_set_send, row=self.row_pulseWidth, sticky='w')
        self.btn_pulsePeriod = tk.Button(self.frame_data, text="Send", command=self.send_pulsePeriodDuty)
        self.btn_pulsePeriod.grid(column=self.column_set_send, row=self.row_pulsePeriod, sticky='w')
        self.btn_packPeriod = tk.Button(self.frame_data, text="Send", command=self.send_packPeriod)
        self.btn_packPeriod.grid(column=self.column_set_send, row=self.row_packPeriod, sticky='w')
        self.btn_pulseN = tk.Button(self.frame_data, text="Send", command=self.send_pulseN)
        self.btn_pulseN.grid(column=self.column_set_send, row=self.row_pulseN, sticky='w')
        self.btn_generation = tk.Button(self.frame_data, text="Off", command=self.generator_on)
        self.btn_generation.grid(column=self.column_set_send, row=self.row_last, sticky='w')
        #########################################################################


        self.frame_image.pack(side=tk.TOP, fill='both')
        self.frame_data.pack(side=tk.LEFT, fill='both')


    def quick_set_load(self):
        # Find required set
        quick_set_name = self.cmb_quick_sets.get()
        quick_set_chosen_one = 0
        for it, one_set in enumerate(self.quick_sets.sets['quick_sets']):
            if(one_set['name'] == quick_set_name):
                quick_set_chosen_one = it
                break

        # Set value parameters in boxes
        self.var_pulseWidth.set(str(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['pulseWidth']))
        self.var_pulsePeriod.set(str(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['pulsePeriod']))
        self.var_packPeriod.set(str(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['packPeriod']))
        self.var_pulseN.set(str(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['pulseN']))

        self.cmb_pulseWidth.current(self.protocol.get_measureCounter(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['pulseWidth_mlt']))
        self.cmb_pulsePeriod.current(self.protocol.get_measureCounter(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['pulsePeriod_mlt']))
        self.cmb_packPeriod.current(self.protocol.get_measureCounter(self.quick_sets.sets['quick_sets'][quick_set_chosen_one]['main']['packPeriod_mlt']))


    def quick_set_remove(self):
        # Find required set
        quick_remove_name = self.cmb_quick_sets.get()
        quick_remove_chosen_one = 0
        for it, one_set in enumerate(self.quick_sets.sets['quick_sets']):
            if(one_set['name'] == quick_remove_name):
                quick_remove_chosen_one = it
                break

        # Remove set and save to json file
        self.quick_sets.sets_remove_set(quick_remove_chosen_one)
        self.quick_sets.sets_save_file()

        # Update quick sets list
        self.quick_sets_list = []
        for name in self.quick_sets.sets['quick_sets']:
            self.quick_sets_list.append(name['name'])
        self.cmb_quick_sets['values'] = self.quick_sets_list
        self.cmb_quick_sets.current(0) # Change to first set


    def quick_set_set(self):
        # Save required parameters
        pulseN_req = int(self.var_pulseN.get())
        pulseWidth_req = int(self.var_pulseWidth.get())
        pulseWidth_meas_req = self.protocol.get_measureCounter(self.cmb_pulseWidth.get())
        pulsePeriod_req = int(self.var_pulsePeriod.get())
        pulsePeriod_meas_req = self.protocol.get_measureCounter(self.cmb_pulsePeriod.get())
        packPeriod_req = int(self.var_packPeriod.get())
        packPeriod_meas_req = self.protocol.get_measureCounter(self.cmb_packPeriod.get())

        self.generator_off(quick_setup=False)

        # Set required parameters
        # Set pack
        self.set_min_parameters() # Set small parameters
        self.var_packPeriod.set(str(packPeriod_req))
        self.cmb_packPeriod.current(packPeriod_meas_req)
        self.send_packPeriod(quick_setup=False)
        # Set pulseN
        #self.set_min_parameters() # Set small parameters
        self.var_pulseN.set(str(pulseN_req))
        self.send_pulseN(quick_setup=False)
        # Set pulse
        #self.set_min_parameters() # Set small parameters
        self.var_pulseWidth.set(str(pulseWidth_req))
        self.cmb_pulseWidth.current(pulseWidth_meas_req)
        self.var_pulsePeriod.set(str(pulsePeriod_req))
        self.cmb_pulsePeriod.current(pulsePeriod_meas_req)
        self.send_pulsePeriodDuty(quick_setup=False)

        # Setup generator
        self.generator_setup()

    def quick_set_save(self):
        set_name = self.ent_quick_name.get()
        if not set_name:
            message = ("Name must not be empty.")
            self.log.log_out(message, 'gui')
            return

        set_data = {
                        "name": set_name,
                        "main": 
                        {
                            "pulseWidth": int(self.var_pulseWidth.get()),
                            "pulseWidth_mlt": self.cmb_pulseWidth.get(),
                            "pulsePeriod": int(self.var_pulsePeriod.get()),
                            "pulsePeriod_mlt": self.cmb_pulsePeriod.get(),
                            "pulseN": int(self.var_pulseN.get()),
                            "packPeriod": int(self.var_packPeriod.get()),
                            "packPeriod_mlt": self.cmb_packPeriod.get()
                        }
                    }

        # Save to json file
        self.quick_sets.sets_save_sets(set_data)
        self.quick_sets.sets_save_file()

        # Update quick sets list
        self.quick_sets_list = []
        for name in self.quick_sets.sets['quick_sets']:
            self.quick_sets_list.append(name['name'])
        self.cmb_quick_sets['values'] = self.quick_sets_list
        for it, name in enumerate(self.quick_sets_list):
            if(name == set_name):
                self.cmb_quick_sets.current(it) # Change to saved set
                break

    def get_impulse_parameters(self, auto_update=False):
        # Log start command
        message = "Interface: get_impulse_parameters() start"
        self.log.log_out_ivent(message)
        # Get parameters from generator
        if not auto_update:
            message = ("Get generator parameters.")
            self.log.log_out(message, 'gui')
        if(self.protocol.check_get_impulse_parameters(self.protocol.get_impulse_parameters())):
            return


        # Render parameters
        pulse = self.protocol.get_valueFromTick(self.protocol.generator['pulseWidth_t'], self.protocol.generator['pulse_psc'], self.protocol.generator['pulseWidth_mlt'])
        pulseWidth_value = pulse['value']
        pulseWidth_mlt = pulse['measure']
        pulseWidth_ctr = pulse['counter']
        self.protocol.generator['pulseWidth'] = self.protocol.get_valueDec(pulse['value'], self.protocol.get_measureHex(pulseWidth_mlt)) # Value in seconds

        pulsePeriod = self.protocol.get_valueFromTick(self.protocol.generator['pulsePeriod_t'], self.protocol.generator['pulse_psc'], self.protocol.generator['pulsePeriod_mlt'])
        pulsePeriod_value = pulsePeriod['value']
        pulsePeriod_mlt = pulsePeriod['measure']
        pulsePeriod_ctr = pulsePeriod['counter']
        self.protocol.generator['pulsePeriod'] = self.protocol.get_valueDec(pulsePeriod['value'], self.protocol.get_measureHex(pulsePeriod_mlt)) # Value in seconds

        pack = self.protocol.get_valueFromTick(self.protocol.generator['packPeriod_t'], self.protocol.generator['pack_psc'], self.protocol.generator['packPeriod_mlt'])
        pack_value = pack['value']
        pack_mlt = pack['measure']
        pack_ctr = pack['counter']
        self.protocol.generator['packPeriod'] = self.protocol.get_valueDec(pack['value'], self.protocol.get_measureHex(pack_mlt)) # Value in seconds

        pulseN_value = self.protocol.generator['pulseN']

        pause = self.protocol.get_modifValue(self.protocol.generator['packPeriod'] - pulseN_value * self.protocol.generator['pulsePeriod'])
        pause_value = pause['value']
        pause_mlt = pause['measure']
        pause_ctr = pause['counter']

        self.lbl_pulseWidth_current_value.configure(text=str(pulseWidth_value))
        self.lbl_pulsePeriod_current_value.configure(text=str(pulsePeriod_value))
        self.lbl_packPeriod_current_value.configure(text=str(pack_value))
        self.lbl_pulseN_current_value.configure(text=str(pulseN_value))
        self.lbl_pause_current_value.configure(text=str(pause_value))

        self.lbl_pulseWidth_current_measure.configure(text=pulseWidth_mlt)
        self.lbl_pulsePeriod_current_measure.configure(text=pulsePeriod_mlt)
        self.lbl_packPeriod_current_measure.configure(text=pack_mlt)
        self.lbl_pause_current_measure.configure(text=pause_mlt)

        # Set value parameters in boxes from current to set
        if not auto_update:
            self.var_pulseWidth.set(str(pulseWidth_value))
            self.var_pulsePeriod.set(str(pulsePeriod_value))
            self.var_packPeriod.set(str(pack_value))
            self.var_pulseN.set(str(pulseN_value))

            self.cmb_pulseWidth.current(pulseWidth_ctr)
            self.cmb_pulsePeriod.current(pulsePeriod_ctr)
            self.cmb_packPeriod.current(pack_ctr)

        if self.protocol.generator['state_generation']:
            self.lbl_generation_value.configure(text='on')
            self.btn_generation.configure(text='off', command=self.generator_off)
        else:
            self.lbl_generation_value.configure(text='off')
            self.btn_generation.configure(text='on', command=self.generator_on)

        # Log end command
        message = "Interface: get_impulse_parameters() end"
        self.log.log_out_ivent(message)

    def send_pulsePeriodDuty(self, quick_setup=True): # quick_setup = false, if setup set
        # Log start command
        message = "Interface: send_pulsePeriodDuty() start"
        self.log.log_out_ivent(message)

        try:
            period = int(self.spn_pulsePeriod.get())
            if(period > MAX_SET_VALUE): # Check max value
                message = "Please enter a smaller value."
                self.log.log_out(message, 'both')
                return
        except ValueError:
            message = "Please enter an integer."
            self.log.log_out(message, 'both')
            return
        try:
            width = int(self.spn_pulseWidth.get())
            if(width > MAX_SET_VALUE):
                message = "Please enter a smaller value."
                self.log.log_out(message, 'both')
                return
        except ValueError:
            message = "Please enter an integer."
            self.log.log_out(message, 'both')
            return

        measure_period = self.protocol.get_measureHex(self.cmb_pulsePeriod.get())
        if(measure_period == uart_error_prefix):
            return
        measure_width = self.protocol.get_measureHex(self.cmb_pulseWidth.get())
        if(measure_width == uart_error_prefix):
            return

        width_dec = self.protocol.get_valueDec(width, measure_width)
        period_dec = self.protocol.get_valueDec(period, measure_period)
        duty = width_dec / period_dec * 100 # In percent

        if(period_dec * self.protocol.generator['pulseN'] >= self.protocol.generator['packPeriod']): # Check fit in pack
            message = "Value of the pulse period and pulse number is more or even than the pack period. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return
        elif(period_dec > MAX_SETUP_TIME): # Check max setup time
            message = "Value of the pulse period very big. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return

        if(width_dec >= period_dec): # Check fit in period
            message = "Value of the pulse width is more or even than the pulse period. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return
        elif(width_dec > MAX_SETUP_TIME): # Check max setup time
            message = "Value of the pulse period very big. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return

        if quick_setup:
            message = ("Send pulse parameters in generator.")
            self.log.log_out(message, 'gui')
        self.protocol.send_pulsePeriodDuty(period, duty, measure_period) # Send pulse parameters
        if quick_setup:
            self.protocol.send_setParameters() # Set
            self.get_impulse_parameters() # Render generator parameters

        # Log end command
        message = "Interface: send_pulsePeriodDuty() end"
        self.log.log_out_ivent(message)

    def send_packPeriod(self, quick_setup=True): # quick_setup = false, if setup set
        # Log start command
        message = "Interface: send_packPeriod() start"
        self.log.log_out_ivent(message)

        try:
            period = int(self.spn_packPeriod.get())
            if(period > MAX_SET_VALUE):
                message = "Please enter a smaller value."
                self.log.log_out(message, 'both')
                return
        except ValueError:
            message = "Please enter an integer."
            self.log.log_out(message, 'both')
            return

        measure_period = self.protocol.get_measureHex(self.cmb_packPeriod.get())
        if(measure_period == uart_error_prefix):
            return
        period_dec = self.protocol.get_valueDec(period, measure_period)

        if(self.protocol.generator['pulsePeriod'] * self.protocol.generator['pulseN'] >= period_dec): # Check fit in pack
            message = "Value of the pulse period and pulse number is more or even than the pack period. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return
        elif(period_dec > MAX_SETUP_TIME): # Check max setup time
            message = "Value of the pulse period very big. Please enter a smaller value."
            self.log.log_out(message, 'both')
            return

        if quick_setup:
            message = ("Send pack period in generator.")
            self.log.log_out(message, 'gui')
        self.protocol.send_packPeriod(period, measure_period) # Send pack period
        if quick_setup:
            self.protocol.send_setParameters() # Set
            self.get_impulse_parameters() # Render generator parameters
        
        # Log end command
        message = "Interface: send_packPeriod() end"
        self.log.log_out_ivent(message)

    def send_pulseN(self, quick_setup=True): # quick_setup = false, if setup set
        # Log start command
        message = "Interface: send_pulseN() start"
        self.log.log_out_ivent(message)

        try:
            pulses = int(self.spn_pulseN.get())
            if(pulses > MAX_PULSES_IN_PACK):
                message = "Please enter a smaller value."
                self.log.log_out(message, 'both')
                return
            elif(self.protocol.generator['pulsePeriod'] * pulses >= self.protocol.generator['packPeriod']): # Check fit in pack
                message = "Value of the pulse period and pulse number is more or even than the pack period. Please enter a smaller value."
                self.log.log_out(message, 'both')
                return
        except ValueError:
            message = "Please enter an integer."
            self.log.log_out(message, 'both')
            return

        if quick_setup:
            message = ("Send number of pulses in pack in generator.")
            self.log.log_out(message, 'gui')
        self.protocol.send_pulseN(pulses) # Send pulseN
        if quick_setup:
            self.protocol.send_setParameters() # Set
            self.get_impulse_parameters() # Render generator parameters
        
        # Log end command
        message = "Interface: send_pulseN() end"
        self.log.log_out_ivent(message)

    def generator_off(self, quick_setup=True): # quick_setup = false, if setup set
        # Log start command
        message = "Interface: generator_off() start"
        self.log.log_out_ivent(message)

        message = "Generator off"
        self.log.log_out(message, 'gui')

        self.protocol.send_set_generatorImpulseOff() # Set generator off
        if quick_setup:
            self.get_impulse_parameters() # Render generator parameters

        # Log end command
        message = "Interface: generator_off() end"
        self.log.log_out_ivent(message)


    def generator_on(self): # quick_setup = false, if setup set
        # Log start command
        message = "Interface: generator_on() start"
        self.log.log_out_ivent(message)

        message = "Generator on"
        self.log.log_out(message, 'gui')

        self.protocol.send_set_generatorImpulseOn() # Set generator on
        self.get_impulse_parameters() # Render generator parameters

        # Log end command
        message = "Interface: generator_on() end"
        self.log.log_out_ivent(message)


    def generator_setup(self):
        # Log start command
        message = "Interface: generator_setup() start"
        self.log.log_out_ivent(message)

        message = "Generator setup"
        self.log.log_out(message, 'gui')

        self.protocol.send_setParameters() # Setup generator
        self.get_impulse_parameters() # Render generator parameters

        # Log end command
        message = "Interface: generator_setup() end"
        self.log.log_out_ivent(message)


    def check_generator_status(self):
        # Log start command
        message = "Interface: check_generator_status() start"
        self.log.log_out_ivent(message)

        # Check generator status
        error = self.protocol.check_get_impulse_parameters(self.protocol.get_impulse_parameters())
        if(error == False):
            message = "Connected to generator."
            self.log.log_out(message, 'both')
            #print(self.protocol.generator)

            # Render generator parameters
            self.get_impulse_parameters()
        else:
            message = "Can't connected to generator."
            self.log.log_out(message, 'both')
        
        # Log end command
        message = "Interface: check_generator_status() end"
        self.log.log_out_ivent(message)
        ########################################################################

    def set_min_parameters(self): # For quick setup
        self.var_pulseN.set(str(1))
        self.var_pulseWidth.set(str(5))
        self.cmb_pulseWidth.current(self.protocol.get_measureCounter('t'))
        self.var_pulsePeriod.set(str(10))
        self.cmb_pulsePeriod.current(self.protocol.get_measureCounter('t'))

    def auto_update(self):
        # Auto update impulse generator parameters
        self.get_impulse_parameters(auto_update=True)
        self.frame_data.after(10000, self.auto_update)