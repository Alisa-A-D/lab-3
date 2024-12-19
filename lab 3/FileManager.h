#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Event.h"
#include <vector>
#include <string>
using namespace std;

class FileManager {
public:
    bool saveEventsToFile(const vector<Event*>& events, const string& filename);
    bool loadEventsFromFile(vector<Event*>& events, const string& filename);
};

#endif 
