import tkinter as tk
from tkinter import ttk
import datetime


class Log():
    def __init__(self, tab, log_file):
        self.frame = ttk.Frame(tab)
        self.log_file = log_file # File for save log
        self.logs = "logs/log_" + datetime.datetime.now().strftime("%Y.%m.%d__%H.%M.%S") + ".txt"
        self.column = 0
        self.row = 0

        ###--- lables
        self.lbl_log = tk.Label(self.frame, text="Log:")
        self.lbl_log.grid(column=self.column, row=self.row, sticky='w')
        self.lbl_log_value_1 = tk.Label(self.frame, text="-----")
        self.lbl_log_value_1.grid(column=self.column, row=self.row + 1, sticky='w')
        self.lbl_log_value_2 = tk.Label(self.frame, text="-----")
        self.lbl_log_value_2.grid(column=self.column, row=self.row + 2, sticky='w')
        self.lbl_log_value_3 = tk.Label(self.frame, text="-----")
        self.lbl_log_value_3.grid(column=self.column, row=self.row + 3, sticky='w')
        self.lbl_log_value_4 = tk.Label(self.frame, text="-----")
        self.lbl_log_value_4.grid(column=self.column, row=self.row + 4, sticky='w')
        self.lbl_log_value_5 = tk.Label(self.frame, text="-----")
        self.lbl_log_value_5.grid(column=self.column, row=self.row + 5, sticky='w')

        self.frame.pack(side=tk.BOTTOM, fill='both')


    def log_out(self, message, direction):
        # Direction == 'file' - in file; 'gui' - in gui; 'both'- in file and in gui

        if(direction == 'file'):
            self.log_in_file(message)
        elif(direction == 'gui'):
            self.log_in_gui(message)
        elif(direction == 'both'):
            self.log_out_ivent(message)
            self.log_in_gui(message)
        else:
            self.log_in_file("Wrong direction")
            self.log_in_file(message)

    def log_in_file(self, message):
        try:
            with open(self.log_file, 'a') as log:
                log.write(datetime.datetime.now().strftime("%Y.%m.%d %H:%M:%S.%f") + " ||  " + message + "\n")
        except FileNotFoundError:
            message = "Log file - 'log.txt' not found."
            self.log_out(message, 'gui')
        try:
            with open(self.logs, 'a') as log:
                log.write(datetime.datetime.now().strftime("%Y.%m.%d %H:%M:%S.%f") + " ||  " + message + "\n")
        except FileNotFoundError:
            message = "Log file - 'log.txt' not found."
            self.log_out(message, 'gui')

    def log_in_gui(self, message):
        self.lbl_log_value_5.configure(text=self.lbl_log_value_4['text'])
        self.lbl_log_value_4.configure(text=self.lbl_log_value_3['text'])
        self.lbl_log_value_3.configure(text=self.lbl_log_value_2['text'])
        self.lbl_log_value_2.configure(text=self.lbl_log_value_1['text'])
        self.lbl_log_value_1.configure(text=(datetime.datetime.now().strftime('%H:%M:%S') + " ||  " + message))

    def log_out_ivent(self, ivent):
        message = "###---"
        self.log_in_file(message)
        message = ivent
        self.log_in_file(message)

    def log_start(self):
        try:
            with open(self.log_file, 'a') as log:
                log.write(" \n")
                log.write("################################################################################\n")
                log.write("####################### Start a new session, good work! ########################\n")
                log.write("################################################################################\n")
                log.write(" \n")
        except FileNotFoundError:
            message = "Log file - 'log.txt' not found."
            log_out(message, 'gui')

        try:
            with open(self.logs, 'w') as log:
                log.write("################################################################################\n")
                log.write("####################### Start a new session, good work! ########################\n")
                log.write("################################################################################\n")
                log.write(" \n")
        except FileNotFoundError:
            message = "Log file - 'log.txt' not found."
            log_out(message, 'gui')