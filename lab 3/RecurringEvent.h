#ifndef RECURRINGEVENT_H
#define RECURRINGEVENT_H

#include "Event.h"

class RecurringEvent : public Event
{
private:
    int startDate[3];
    int endDate[3];
    int repeats;

public:
    RecurringEvent();
    RecurringEvent(const string& name, double duration, int sd, int sm, int sy,
    int ed, int em, int ey, int repeats);

    void displayEvent() const override;
    int getRepeats() const;
    RecurringEvent& inputEventDetails() override;


    const int* getStartDate() const; 
    const int* getEndDate() const;   

};

#endif
