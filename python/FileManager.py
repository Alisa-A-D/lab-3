from SingleEvent import SingleEvent
from RecurringEvent import RecurringEvent



class FileManager:

    def save_events_to_file(events, filename):
        
            with open(filename, 'w') as out_file:
                for event in events:
                    if isinstance(event, SingleEvent):
                        out_file.write(f"SingleEvent {event.get_name()} {event.get_duration()} {event.get_date()[0]} {event.get_date()[1]} {event.get_date()[2]}\n")
                    elif isinstance(event, RecurringEvent):
                        out_file.write(f"RecurringEvent {event.get_name()} {event.get_duration()} {event.get_start_date()[0]} {event.get_start_date()[1]} {event.get_start_date()[2]} {event.get_end_date()[0]} {event.get_end_date()[1]} {event.get_end_date()[2]} {event.get_repeats()}\n")
            


    def load_events_from_file(events, filename):
   
            with open(filename, 'r') as in_file:
                events.clear()
                for line in in_file:
                    parts = line.strip().split()
                    event_type = parts[0]

                    if event_type == "SingleEvent":
                        name = parts[1]
                        duration = float(parts[2])
                        day = int(parts[3])
                        month = int(parts[4])
                        year = int(parts[5])
                        events.append(SingleEvent(name, duration, day, month, year))
                    elif event_type == "RecurringEvent":
                        name = parts[1]
                        duration = float(parts[2])
                        s_day = int(parts[3])
                        s_month = int(parts[4])
                        s_year = int(parts[5])
                        e_day = int(parts[6])
                        e_month = int(parts[7])
                        e_year = int(parts[8])
                        repeats = int(parts[9])
                        events.append(RecurringEvent(name, duration, s_day, s_month, s_year, e_day, e_month, e_year, repeats))
        
