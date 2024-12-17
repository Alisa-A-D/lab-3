#ifndef RECURRINGEVENT_H
#define RECURRINGEVENT_H

#include "Event.h"
#include <string>
using namespace std;

class RecurringEvent : public Event
{
private:
	int startDate[3];
	int endDate[3];
	int repeats;
public:
	RecurringEvent();
	RecurringEvent(string& name, double duration, int sDay, int sMonth, int sYear, int eDay, int eMonth, int eYear, int repeats);
	void displayEvent();
	int getRepeats();
	RecurringEvent& inputEventDetails();
};

#endif
