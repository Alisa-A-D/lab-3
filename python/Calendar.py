from FileManager import FileManager
from SingleEvent import SingleEvent
from ReccuringEvent import ReccuringEvent


class Calendar:
    def __init__(self):
        self.events = []

    def add_event(self, event):
        self.events.append(event)

    def find_shortest_event(self):
        start_day, start_month, start_year = map(int, input("Enter start date (day month year): ").split())
        end_day, end_month, end_year = map(int, input("Enter end date (day month year): ").split())

        filtered_events = self.filter_events_by_date(start_day, start_month, start_year, end_day, end_month, end_year)

        if not filtered_events:
            return None

        shortest_event = filtered_events[0]
        for event in filtered_events:
            if event.get_duration() < shortest_event.get_duration():
                shortest_event = event

        return shortest_event

    def find_longest_event(self):
        start_day, start_month, start_year = map(int, input("Enter start date (day month year): ").split())
        end_day, end_month, end_year = map(int, input("Enter end date (day month year): ").split())

        filtered_events = self.filter_events_by_date(start_day, start_month, start_year, end_day, end_month, end_year)

        if not filtered_events:
            return None

        longest_event = filtered_events[0]
        for event in filtered_events:
            if event.get_duration() > longest_event.get_duration():
                longest_event = event

        return longest_event

    def calculate_sum_duration(self):
        start_day, start_month, start_year = map(int, input("Enter start date (day month year): ").split())
        end_day, end_month, end_year = map(int, input("Enter end date (day month year): ").split())

        filtered_events = self.filter_events_by_date(start_day, start_month, start_year, end_day, end_month, end_year)

        total = 0.0
        for event in filtered_events:
            if isinstance(event, ReccuringEvent):
                total += event.get_duration() * event.get_repeats()
            else:
                total += event.get_duration()

        return total

    def average_repeats(self):
        total_repeats = 0
        count = 0

        for event in self.events:
            if isinstance(event, ReccuringEvent):
                total_repeats += event.get_repeats()
                count += 1

        return 0 if count == 0 else total_repeats // count

    def display_all_events(self):
        for event in self.events:
            event.display_event()

    def save_to_file(self, filename):
        return FileManager.save_events_to_file(self.events, filename)

    def load_from_file(self, filename):
        return FileManager.load_events_from_file(self.events, filename)

    def filter_events_by_date(self, start_day, start_month, start_year,
                              end_day, end_month, end_year):
        filtered_events = []

        for event in self.events:
            if isinstance(event, SingleEvent):
                day, month, year = event.get_date()

                if ((year > start_year or (year == start_year and (month > start_month or (month == start_month and day >= start_day)))) and
                    (year < end_year or (year == end_year and (month < end_month or (month == end_month and day <= end_day))))):
                    filtered_events.append(event)

            elif isinstance(event, ReccuringEvent):
                s_day, s_month, s_year = event.get_start_date()
                e_day, e_month, e_year = event.get_end_date()

                overlaps = ((s_year < end_year or (s_year == end_year and (s_month < end_month or (s_month == end_month and s_day <= end_day)))) and
                            (e_year > start_year or (e_year == start_year and (e_month > start_month or (e_month == start_month and e_day >= start_day)))))

                if overlaps:
                    filtered_events.append(event)

        return filtered_events
