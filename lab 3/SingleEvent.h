#ifndef SINGLEEVENT_H
#define SINGLEEVENT_H

#include "Event.h"
using namespace std;

class SingleEvent : public Event
{
private:
    int date[3];
public:
    SingleEvent();
    SingleEvent(const string& name, double duration, int dd, int mm, int yy);

    void displayEvent() const override;
    SingleEvent& inputEventDetails() override;


    const int* getDate() const; 

};

#endif
