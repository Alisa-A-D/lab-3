from Calendar import Calendar
from SingleEvent import SingleEvent
from RecurringEvent import RecurringEvent


class Menu:
    def __init__(self, calendar):
        self.calendar = calendar

    def display_menu(self):
        while True:
            print("1. Add single event")
            print("2. Add recurring event")
            print("3. Display all events")
            print("4. The shortest event")
            print("5. The longest event")
            print("6. Sum duration of all events")
            print("7. Average repeats of recurring event")
            print("8. Save to file")
            print("9. Upload from file")
            print("0. Exit")

            choice = input("Your choice: ")

            try:
                choice = int(choice)
            except ValueError:
                print("Invalid choice")
                continue

            if choice == 1:
                event = SingleEvent()
                event.input_event_details()
                self.calendar.add_event(event)
                print()

            elif choice == 2:
                event = RecurringEvent()
                event.input_event_details()
                self.calendar.add_event(event)
                print()

            elif choice == 3:
                self.calendar.display_all_events()
                print()

            elif choice == 4:
                shortest = self.calendar.find_shortest_event()
                if shortest:
                    shortest.display_event()
                else:
                    print("No event found.")
                print()

            elif choice == 5:
                longest = self.calendar.find_longest_event()
                if longest:
                    longest.display_event()
                else:
                    print("No event found.")
                print()

            elif choice == 6:
                print(f"Sum duration: {self.calendar.calculate_sum_duration()} hours.")
                print()

            elif choice == 7:
                print(f"Average repeats: {self.calendar.average_repeats()}")
                print()

            elif choice == 8:
                if self.calendar.save_to_file("events.txt"):
                    print("Saved")
                else:
                    print("Failed to save.")
                print()

            elif choice == 9:
                if self.calendar.load_from_file("events.txt"):
                    print("Uploaded")
                else:
                    print("Failed to load.")
                print()

            elif choice == 0:
                break

            else:
                print("Invalid choice")
