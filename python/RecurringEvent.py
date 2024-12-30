from Event import Event

class ReccuringEvent(Event):
    def __init__(self, line, dur, sdd, smm, syy, edd, emm, eyy, rep):
        super().__init__(line, dur)
        self._start_date=[sdd, smm, syy]
        self._end_date=[edd, emm, eyy]
        self._repeats=rep
    
    def get_start_date(self):
        return self._start_date
        
    def get_end_date(self):
        return self._end_date
    
    def display_event(self):
        print(f"{self._name}: {self._start_date[0]}.{self._start_date[1]}.{self._start_date[2]}-{self._end_date[0]}.{self._end_date[1]}.{self._end_date[2]}, Repeats: {self._repeats}, Duration: {self._duration}")
        
    def input_event_details(self):
        print(f"Enter information about event: ")
        self._name=input("Name: ")
        self._duration=float(input("Duration: "))
        print(f"Start date:")
        self._start_date[0]=int(input("day: "))
        self._start_date[1]=int(input("month: "))
        self._start_date[2]=int(input("year: "))
        print(f"End date:")
        self._end_date[0]=int(input("day: "))
        self._end_date[1]=int(input("month: "))
        self._end_date[2]=int(input("year: "))
        self._repeats=int(input("repeats: "))
