#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event 
{
protected:
    string name;
    double duration;
public:
    Event();
    Event(const string& name, double duration);
    virtual ~Event() = default;

    virtual void displayEvent() const = 0;
    string getName() const;
    double getDuration() const;
    virtual Event& inputEventDetails() = 0;
};

#endif
