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
	Event(string& name, double  duration);
	virtual void displayEvent() = 0;
	string& getName();
	double getDuration();
	virtual Event& inputEventDetails() = 0;
};

#endif
