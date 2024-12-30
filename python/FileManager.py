from SingleEvent import SingleEvent
from ReccuringEvent import ReccuringEvent

class FileManager:


    def save_events_to_file(events, filename):
        with open(filename, 'w') as out_file:
            for event in events:
                if isinstance(event, SingleEvent):
                    out_file.write(f"SingleEvent {event.get_name()} {event.get_duration()} {event.get_date()[0]} {event.get_date()[1]} {event.get_date()[2]}\n")
                elif isinstance(event, ReccuringEvent):
                    out_file.write(f"ReccuringEvent {event.get_name()} {event.get_duration()} {event.get_start_date()[0]} {event.get_start_date()[1]} {event.get_start_date()[2]} "
                                   f"{event.get_end_date()[0]} {event.get_end_date()[1]} {event.get_end_date()[2]} {event.get_repeats()}\n")
        return True


    def load_events_from_file(events, filename):
        with open(filename, 'r') as in_file:
            events.clear()
            for line in in_file:
                parts = line.strip().split()
                event_type = parts[0]

                if event_type == "SingleEvent":
                    name = parts[1]
                    duration = float(parts[2])
                    day, month, year = map(int, parts[3:6])
                    events.append(SingleEvent().change_event(name, duration, day, month, year))

                elif event_type == "ReccuringEvent":
                    name = parts[1]
                    duration = float(parts[2])
                    s_day, s_month, s_year = map(int, parts[3:6])
                    e_day, e_month, e_year = map(int, parts[6:9])
                    repeats = int(parts[9])
                    events.append(ReccuringEvent().change_event(name, duration, s_day, s_month, s_year, e_day, e_month, e_year, repeats))
        return True
