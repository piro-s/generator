###--- global
MCU_FREQ = 72000000 # Frequency STM32
ERROR_DELTA_LOG = 0.001 # Relative deviation in percentage between the calculated period and the required
MAX_SET_VALUE = 9999 # For spinbox, more --> error in set value
MAX_PULSES_IN_PACK = 2048 # Same in STM32
MAX_DECIMAL = 3 # Number of digits after decimal point
MAX_SETUP_TIME = 1 # Can't set value more then 1s (more at your own risk)


###--- errors
uart_error_no             = 0x90 # No error
uart_error_xor            = 0x91 # Wrong XOR
uart_error_sum            = 0x92 # Wrong SUM
uart_error_time           = 0x93 # Long waiting pack
uart_error_command        = 0x94 # Wrong receive command
uart_error_empty          = 0x95 # Empty received data
uart_error_prefix         = 0x96 # Wrong prefix


###--- byte number
uart_n_start              = 0
uart_n_quantity           = 1 # Number of byte in pack
uart_n_command            = 2
uart_n_value              = 3 # 2 byte
uart_n_response           = 3
uart_n_measure            = 5
uart_n_presscale          = 6 # 2  byte
uart_n_sum                = 2 # Quantity - 2
uart_n_xor                = 1 # Quantity - 1


###--- pack length
uart_pack_getParameters   = 5
uart_pack_setParameters   = 5
uart_pack_response        = 6
uart_pack_temp            = 7
uart_pack_pulseN          = 7
uart_pack_period          = 10
uart_pack_pulseWidth      = 8


###--- command
uart_com_start            = 0xA5
uart_com_stop             = 0x5A
uart_com_send_pulseWidth  = 0x70 # Save from pc
uart_com_send_pulsePeriod = 0x71 # Save from pc
uart_com_send_packPeriod  = 0x72 # Save from pc
uart_com_send_pulseN      = 0x73 # Save from pc
uart_com_get_pulseWidth   = 0x80 # Send on pc
uart_com_get_pulsePeriod  = 0x81 # Send on pc
uart_com_get_packPeriod   = 0x82 # Send on pc
uart_com_get_pulseN       = 0x83 # Send on pc
uart_com_get_BMP180       = 0x90 # Send sensor availability
uart_com_get_temp         = 0x91 # Send temp on pc
uart_com_set_parameters   = 0xE0 # Set parameters from generator_rec
uart_com_on               = 0xE1 # On generator
uart_com_off              = 0xE2 # Off generator
uart_com_generation       = 0xE3 # Generation state


###--- measure
uart_measure_n            = 0x6E # us
uart_measure_u            = 0x75 # us
uart_measure_m            = 0x6D # ms
uart_measure_s            = 0x73 # s
uart_measure_t            = 0x74 # tick