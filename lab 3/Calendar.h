#ifndef CALENDAR_H
#define CALENDAR_H

#include "Event.h"
#include "FileManager.h"
#include <vector>

class Calendar {
private:
    std::vector<Event*> events;
    FileManager fileManager;

public:
    void addEvent(Event* event);
    Event* findShortestEvent() const;
    Event* findLongestEvent() const;
    double calculateSumDuration() const;
    int averageRepeats() const;
    void displayAllEvents() const;
    bool saveToFile(const std::string& filename);
    bool loadFromFile(const std::string& filename);
};

#endif