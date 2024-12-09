#include "Calendar.h"
#include "RecurringEvent.h"
#include <iostream>
using namespace std;

void Calendar::addEvent(Event* event) {
    events.push_back(event);
}

Event* Calendar::findShortestEvent() const {
    if (events.empty()) return nullptr;

    Event* shortestEvent = events[0];
    for (const auto& event : events) {
        if (event->getDuration() < shortestEvent->getDuration()) {
            shortestEvent = event;
        }
    }
    return shortestEvent;
}

Event* Calendar::findLongestEvent() const {
    if (events.empty()) return nullptr;

    Event* longestEvent = events[0];
    for (const auto& event : events) {
        if (event->getDuration() > longestEvent->getDuration()) {
            longestEvent = event;
        }
    }
    return longestEvent;
}

double Calendar::calculateSumDuration() const {
    double total = 0.0;
    for (const auto& event : events) {
        total += event->getDuration();
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
