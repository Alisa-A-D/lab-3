from Event import Event

class SingleEvent(Event):
    def __init__(self, line, dur, dd, mm, yy):
        super().__init__(line, dur)
        self._date=[dd, mm, yy]
    
    def get_date(self):
        return self._date
    
    def display_event(self):
        print(f"{self._name}: {self._date[0]}.{self._date[1]}.{self._date[2]}, Duration: {self._duration}")
        
    def input_event_details(self):
        print(f"Enter information about event:\n")
        self._name=input("name: ")
        self._duration=float(input("duration: "))
        self._date[0]=int(input("day: "))
        self._date[1]=int(input("month: "))
        self._date[2]=int(input("year: "))
