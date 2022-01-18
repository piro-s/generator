import serial.tools.list_ports

import tkinter as tk
from tkinter import ttk
from protocol import *


class Setup():
    def __init__(self, tab, log, protocol):
        self.frame = ttk.Frame(tab)
        self.log = log
        self.protocol = protocol

        self.column_begin = 0
        self.row_begin = 0

        self.protocol.comport_refresh()

        ###--- lables
        self.lbl_comport = tk.Label(self.frame, text="COM port:")
        self.lbl_comport.grid(column=self.column_begin, row=self.row_begin, sticky='e')


        ###--- comboboxes
        self.cmb_comport = ttk.Combobox(self.frame, width=10)
        self.cmb_comport['values'] = self.protocol.ports
        self.cmb_comport.current(0) # Default option
        self.cmb_comport.grid(column=self.column_begin + 1, row=self.row_begin)


        ###--- checkboxes
        #self.chk_log_new_session = ttk.Checkbutton(frame, text="Continue log", var=log_new_session)
        #self.chk_log_new_session.grid(column=self.column_begin, row=self.row_begin + 1)


        ###--- buttons
        self.btn_comport = tk.Button(self.frame, text='Connect', command=self.comport_connect)
        self.btn_comport.grid(column=self.column_begin + 2, row=self.row_begin, sticky='w')
        self.btn_comport_refresh = tk.Button(self.frame, text='Refresh', command=self.comport_refresh)
        self.btn_comport_refresh.grid(column=self.column_begin + 3, row=self.row_begin, sticky='w')
        ################################################################################

        self.frame.pack(side=tk.TOP, fill='both')

    def comport_refresh(self):
        self.protocol.comport_refresh()
        self.cmb_comport['values'] = self.protocol.ports

    def comport_connect(self):
        error = self.protocol.com_open(self.cmb_comport.get())
        if not error:
            self.btn_comport.configure(text='Disconnect', command=self.comport_disconnect)
            message = ("Connected to COM port.")
            self.log.log_out(message, 'gui')

    def comport_disconnect(self):
        error = self.protocol.com_close()
        if not error:
            message = ("Disconnected from COM port.")
            self.log.log_out(message, 'gui')
            self.btn_comport.configure(text='Connect', command=self.comport_connect)