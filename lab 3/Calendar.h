#ifndef CALENDAR_H
#define CALENDAR_H
using namespace std;

#include "Event.h"
#include "FileManager.h"
#include <vector>

class Calendar {
private:
    vector<Event*> events;
    FileManager fileManager;

public:
    void addEvent(Event* event);
    Event* findShortestEvent() const;
    Event* findLongestEvent() const;
    double calculateSumDuration() const;
    int averageRepeats() const;
    void displayAllEvents() const;
    bool saveToFile(const string& filename);
    bool loadFromFile(const string& filename);

    std::vector<Event*> filterEventsByDate(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) const;

};

#endif
