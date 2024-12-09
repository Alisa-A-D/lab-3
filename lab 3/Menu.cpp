#include "Menu.h"
#include "SingleEvent.h"
#include "RecurringEvent.h"
#include <iostream>
using namespace std;

void Menu::displayMenu() {
    int choice;
    do {
        cout << "\n1. Add single event \n";
        cout << "2. Add recurring event\n";
        cout << "3. Display all events\n";
        cout << "4. The shortest event\n";
        cout << "5. The longest event\n";
        cout << "6. Sum duration of all events\n";
        cout << "7. Average repeats of recurring event\n";
        cout << "8. Save to file\n";
        cout << "9. Save from file\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            auto event = new SingleEvent();
            event->inputEventDetails();
            calendar.addEvent(event);
            break;
        }
        case 2: {
            auto event = new RecurringEvent();
            event->inputEventDetails();
            calendar.addEvent(event);
            break;
        }
        case 3:
            calendar.displayAllEvents();
            break;
        case 4: {
            auto shortest = calendar.findShortestEvent();
            if (shortest) shortest->displayEvent();
            else cout << "None event.\n";
            break;
        }
        case 5: {
            auto longest = calendar.findLongestEvent();
            if (longest) longest->displayEvent();
            else cout << "None event.\n";
            break;
        }
        case 6:
            cout << "Sum duration: " << calendar.calculateSumDuration() << " hours.\n";
            break;
        case 7:
            cout << "Average repeats: " << calendar.averageRepeats() << endl;
            break;
        case 8:
            if (calendar.saveToFile("events.txt")) cout << "Saved\n";
            break;
        case 9:
            if (calendar.loadFromFile("events.txt")) cout << "Uploaded\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
}
