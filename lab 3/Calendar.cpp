#include "Calendar.h"
#include "RecurringEvent.h"
#include "SingleEvent.h"
#include <iostream>
using namespace std;

void Calendar::addEvent(Event* event) {
    events.push_back(event);
}

Event* Calendar::findShortestEvent() const {
    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    cout << "Enter start date (day month year): ";
    cin >> startDay >> startMonth >> startYear;
    cout << "Enter end date (day month year): ";
    cin >> endDay >> endMonth >> endYear;

    vector<Event*> filteredEvents = filterEventsByDate(startDay, startMonth, startYear, endDay, endMonth, endYear);

    if (filteredEvents.empty()) return nullptr;

    Event* shortestEvent = filteredEvents[0];
    for (const auto& event : filteredEvents) {
        if (event->getDuration() < shortestEvent->getDuration()) {
            shortestEvent = event;
        }
    }
    return shortestEvent;
}


Event* Calendar::findLongestEvent() const {

    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    cout << "Enter start date (day month year): ";
    cin >> startDay >> startMonth >> startYear;
    cout << "Enter end date (day month year): ";
    cin >> endDay >> endMonth >> endYear;

    vector<Event*> filteredEvents = filterEventsByDate(startDay, startMonth, startYear, endDay, endMonth, endYear);

    if (filteredEvents.empty()) return nullptr;

    Event* longestEvent = filteredEvents[0];
    for (const auto& event : filteredEvents) {
        if (event->getDuration() > longestEvent->getDuration()) {
            longestEvent = event;
        }
    }
    return longestEvent;
}

double Calendar::calculateSumDuration() const {


    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    cout << "Enter start date (day month year): ";
    cin >> startDay >> startMonth >> startYear;
    cout << "Enter end date (day month year): ";
    cin >> endDay >> endMonth >> endYear;

    vector<Event*> filteredEvents = filterEventsByDate(startDay, startMonth, startYear, endDay, endMonth, endYear);

    double total = 0.0;

    for (const auto& filteredEvents : filteredEvents) {
        auto recurringEvent = dynamic_cast<RecurringEvent*>(filteredEvents);
        if (recurringEvent) {
            total += recurringEvent->getDuration() * recurringEvent->getRepeats();
        }
        else {
            total += filteredEvents->getDuration();
        }
    }

    return total;
}


int Calendar::averageRepeats() const {
    int totalRepeats = 0, count = 0;
    for (const auto& event : events) {
        auto recurringEvent = dynamic_cast<RecurringEvent*>(event);
        if (recurringEvent) {
            totalRepeats += recurringEvent->getRepeats();
            count++;
        }
    }
    return count == 0 ? 0 : totalRepeats / count;
}

void Calendar::displayAllEvents() const {
    for (const auto& event : events) {
        event->displayEvent();
    }
}

bool Calendar::saveToFile(const string& filename) {
    return fileManager.saveEventsToFile(events, filename);
}

bool Calendar::loadFromFile(const string& filename) {
    return fileManager.loadEventsFromFile(events, filename);
}

vector<Event*> Calendar::filterEventsByDate(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) const {
    vector<Event*> filteredEvents;

    for (const auto& event : events) {
        SingleEvent* singleEvent = dynamic_cast<SingleEvent*>(event);
        RecurringEvent* recurringEvent = dynamic_cast<RecurringEvent*>(event);

        if (singleEvent) {

            const int* date = singleEvent->getDate();
            int day = date[0];
            int month = date[1];
            int year = date[2];

            if ((year > startYear || (year == startYear && (month > startMonth || (month == startMonth && day >= startDay)))) &&
                (year < endYear || (year == endYear && (month < endMonth || (month == endMonth && day <= endDay))))) {
                filteredEvents.push_back(singleEvent);
            }
        }
        else if (recurringEvent) {

            const int* startDate = recurringEvent->getStartDate();
            const int* endDate = recurringEvent->getEndDate();

            int sDay = startDate[0], sMonth = startDate[1], sYear = startDate[2];
            int eDay = endDate[0], eMonth = endDate[1], eYear = endDate[2];

            bool overlaps = (sYear < endYear || (sYear == endYear && (sMonth < endMonth || (sMonth == endMonth && sDay <= endDay)))) &&
                (eYear > startYear || (eYear == startYear && (eMonth > startMonth || (eMonth == startMonth && eDay >= startDay))));

            if (overlaps) {
                filteredEvents.push_back(recurringEvent);
            }
        }
    }

    return filteredEvents;
}

