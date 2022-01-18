from impulse import *
from log_out import *
from protocol import *
from setup import *


class Generator():
    def __init__(self):
        ###--- windows
        self.window = tk.Tk()
        self.window.title("generator")
        self.window.resizable(False, False) # Don't allow expend window

        ###--- tabs
        self.tab_control = ttk.Notebook(self.window)
        self.tab_impulse = ttk.Frame(self.tab_control)
        self.tab_setup = ttk.Frame(self.tab_control)

        self.log = Log(self.tab_impulse, 'log.txt')
        self.log.log_start()

        self.protocol = Protocol(self.log)

        self.frame_setup = Setup(self.tab_setup, self.log, self.protocol)
        self.frame_impulse = Impulse(self.tab_impulse, self.log, self.protocol)

        self.tab_control.add(self.tab_impulse, text='Impulse')
        self.tab_control.add(self.tab_setup, text='Setup')
        self.tab_control.pack(side=tk.TOP, fill='both')

        self.comport_enter()
        self.frame_impulse.auto_update()

        self.window.focus_force()
        self.frame_impulse.check_generator_status()

        self.window.mainloop()
        self.protocol.com_close()


    ###--- functions
    def comport_enter(self):
        try:
            self.protocol.comport_refresh()

            top = tk.Toplevel(self.window)
            top.transient(self.window)
            tk.Label(top, text='Select COM port: ').pack()
            box_value = tk.StringVar()
            combo = ttk.Combobox(top, textvariable=box_value, values=self.protocol.ports, state='readonly')
            combo.pack()
            combo.bind('<<ComboboxSelected>>', lambda _: top.destroy())
            
            self.window.grab_set()
            self.window.wait_window(top) # Wait for itself destroyed, so like a modal dialog

            port = box_value.get()
            self.frame_setup.cmb_comport.current(self.protocol.ports.index(port))
            self.frame_setup.comport_connect()
        except ValueError:
            message = "No connect with COM port."
            self.log.log_out(message, 'gui')