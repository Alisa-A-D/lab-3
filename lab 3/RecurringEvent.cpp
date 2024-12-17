#include <iostream>
#include "RecurringEvent.h"
using namespace std;

RecurringEvent::RecurringEvent():Event()
{
	for (int &i : startDate) {
		i = 0;
	}
	for (int &i : endDate) {
		i = 0;
	}
	repeats = 0;
}
RecurringEvent::RecurringEvent(string& name, double duration, int sd, int sm, int sy, int ed, int em, int ey, int repeats) : Event(name, duration), repeats(repeats)
{
	startDate[0] = sd; startDate[1] = sm; startDate[2] = sy;
	endDate[0] = ed; endDate[1] = em; endDate[2] = ey;
};
void RecurringEvent::displayEvent()
{
	cout << name << ":" << startDate[0] << "." << startDate[1] << "." << startDate[2] << " - " <<
		endDate[0] << "." << endDate[1] << "." << endDate[2] <<
		endl << "Repeats:" << repeats << endl;
};
int RecurringEvent::getRepeats() { return repeats; };
RecurringEvent& RecurringEvent::inputEventDetails()
{
	cout << "Enter information about event: name, duration, start date(day, month, year),  end date(day, month, year), repeats" << endl;
	cin >> name >> duration >> startDate[0] >> startDate[1] >> startDate[2] >> endDate[0] >> endDate[1] >> endDate[2] >> repeats;
	return *this;
}
