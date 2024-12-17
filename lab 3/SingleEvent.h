#ifndef SINGLEEVENT_H
#define SINGLEEVENT_H

#include "Event.h"
#include <string>
using namespace std;

class SingleEvent: public Event
{
private:
	int date[3];
public:
	SingleEvent();
	SingleEvent(string& name, double duration, int day, int month, int year);
	void displayEvent();
	SingleEvent& inputEventDetails();
};

#endif
