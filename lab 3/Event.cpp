#include "Event.h"

Event::Event()
{
	name = ""; duration = 0;
};
Event::Event(const string& name, double duration) : name(name), duration(duration) {}

string Event::getName() const { return name; }

double Event::getDuration() const { return duration; }
