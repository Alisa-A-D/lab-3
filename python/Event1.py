from abc import ABC, abstractmethod

class Event(ABC):
    def __init__(self, line, dur):
        self._name=line
        self._duration=dur
        
    def get_name(self):
        return self._name
            
    def get_duration(self):
        return self._duration
        
    @abstractmethod
    def display_event(self):
        pass
        
    @abstractmethod
    def input_event_details(self):
        pass
