import json


class Quick_sets():
    def __init__(self):
        self.sets_json = "quick_sets.json"
        self.sets = []

    def sets_load_file(self):
        try:
            with open(self.sets_json, 'r') as json_file:
                self.sets = json.load(json_file)
        except ValueError:
            self.sets = { # Test set
                "quick_sets": 
                [
                    {
                        "name": "test",
                        "main": 
                        {
                            "pulseWidth": 2,
                            "pulseWidth_mlt": "u",
                            "pulsePeriod": 7,
                            "pulsePeriod_mlt": "u",
                            "pulseN": 3,
                            "packPeriod": 55,
                            "packPeriod_mlt": "u"
                        }
                    }
                ]
            }

    def sets_remove_set(self, index):
        self.sets["quick_sets"].pop(index)

    def sets_save_file(self):
        if(self.sets != 0):
            with open(self.sets_json, 'w') as json_file:
                json.dump(self.sets, json_file)
        else:
            # print("Empty sets, no saving.")
            pass

    def sets_save_sets(self, data):
        self.sets["quick_sets"].append(data)

    def sets_print(self):
        print(self.sets)