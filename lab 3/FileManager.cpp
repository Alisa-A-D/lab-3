#include "FileManager.h"
#include "SingleEvent.h"
#include "RecurringEvent.h"
#include <fstream>
#include <iostream>
using namespace std;

bool FileManager::saveEventsToFile(const vector<Event*>& events, const string& filename)
{
    ofstream outFile(filename);
    if (!outFile) return false;

    for (const auto& event : events)
    {
        auto singleEvent = dynamic_cast<SingleEvent*>(event);
        if (singleEvent) {
            outFile << "SingleEvent "
                << singleEvent->getName() << " "
                << singleEvent->getDuration() << " "
                << singleEvent->getDate()[0] << " "
                << singleEvent->getDate()[1] << " "
                << singleEvent->getDate()[2] << endl;
        }
        else {
            auto recurringEvent = dynamic_cast<RecurringEvent*>(event);
            if (recurringEvent) {
                outFile << "RecurringEvent "
                    << recurringEvent->getName() << " "
                    << recurringEvent->getDuration() << " "
                    << recurringEvent->getStartDate()[0] << " "
                    << recurringEvent->getStartDate()[1] << " "
                    << recurringEvent->getStartDate()[2] << " "
                    << recurringEvent->getEndDate()[0] << " "
                    << recurringEvent->getEndDate()[1] << " "
                    << recurringEvent->getEndDate()[2] << " "
                    << recurringEvent->getRepeats() << endl;
            }
        }
    }

    return true;
}


bool FileManager::loadEventsFromFile(vector<Event*>& events, const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) return false;

    events.clear();
    string type;

    while (inFile >> type) {
        if (type == "SingleEvent") {
            string name;
            double duration;
            int day, month, year;

            inFile >> ws; 
            getline(inFile, name, ' ');
            inFile >> duration >> day >> month >> year;

            events.push_back(new SingleEvent(name, duration, day, month, year));
        }
        else if (type == "RecurringEvent") {
            string name;
            double duration;
            int sDay, sMonth, sYear, eDay, eMonth, eYear, repeats;

            inFile >> ws; 
            getline(inFile, name, ' ');
            inFile >> duration >> sDay >> sMonth >> sYear
                >> eDay >> eMonth >> eYear >> repeats;

            events.push_back(new RecurringEvent(name, duration, sDay, sMonth, sYear, eDay, eMonth, eYear, repeats));
        }
    }

    return true;
}

