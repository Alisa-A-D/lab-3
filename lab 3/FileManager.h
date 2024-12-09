#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Event.h"
#include <vector>
#include <string>

class FileManager {
public:
    bool saveEventsToFile(const std::vector<Event*>& events, const std::string& filename);
    bool loadEventsFromFile(std::vector<Event*>& events, const std::string& filename);
};

#endif 