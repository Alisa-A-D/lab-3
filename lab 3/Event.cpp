#include <iostream>
#include "Event.h"
using namespace std;

Event::Event() 
{
	name = ""; duration = 0;
};
Event::Event(string& name, double duration) : name(name), duration(duration) {};
string& Event::getName() { return name; };
double Event::getDuration() { return duration; };
