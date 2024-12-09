#include "FileManager.h"
#include "SingleEvent.h" 
#include <fstream>
#include <iostream>
using namespace std;

bool FileManager::saveEventsToFile(const vector<Event*>& events, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error" << endl;
        return false;
    }
    for (const auto& event : events) {
        outFile << event->getName() << "|" << event->getDuration() << endl;
    }
    outFile.close();
    return true;
}

bool FileManager::loadEventsFromFile(vector<Event*>& events, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error" << endl;
        return false;
    }

    events.clear();
    string name;
    double duration;
    while (inFile >> ws && getline(inFile, name, '|') && inFile >> duration) {
        events.push_back(new SingleEvent(name, duration)); 
    }
    inFile.close();
    return true;
}
