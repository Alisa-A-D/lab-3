#include <iostream>
#include "RecurringEvent.h"
using namespace std;

RecurringEvent::RecurringEvent() :Event()
{
    for (int& i : startDate) {
        i = 0;
    }
    for (int& i : endDate) {
        i = 0;
    }
    repeats = 0;
}

RecurringEvent::RecurringEvent(const string& name, double duration, int sd, int sm, int sy,
    int ed, int em, int ey, int repeats)
    : Event(name, duration), repeats(repeats)
{
    startDate[0] = sd; startDate[1] = sm; startDate[2] = sy;
    endDate[0] = ed; endDate[1] = em; endDate[2] = ey;

}

void RecurringEvent::displayEvent() const
{
    cout << "Recurring Event: " << name 
        << ",  " << startDate[0] << "." << startDate[1] << "." << startDate[2]
        << " - " << endDate[0] << "." << endDate[1] << "." << endDate[2]
         << ", Repeats: " << repeats << ", Duration: " << duration << endl;
}

int RecurringEvent::getRepeats() const { return repeats; }
const int* RecurringEvent::getStartDate() const { return startDate;}
const int* RecurringEvent::getEndDate() const {return endDate;}


RecurringEvent& RecurringEvent::inputEventDetails()
{
    cout << "Enter information about event: name, duration, start date(day, month, year),  end date(day, month, year), repeats" << endl;
    cin >> name >> duration >> startDate[0] >> startDate[1] >> startDate[2] >> endDate[0] >> endDate[1] >> endDate[2] >> repeats;
    return *this;
}
