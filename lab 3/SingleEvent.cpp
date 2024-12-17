#include <iostream>
#include "SingleEvent.h"
using namespace std;

SingleEvent::SingleEvent():Event()
{
	for (int i:date) {
		i = 0;
	}
}
SingleEvent::SingleEvent(string& name, double duration, int dd, int mm, int yy) : Event(name, duration) 
{
	date[0] = dd; date[1] = mm; date[2] = yy;
};
void SingleEvent::displayEvent() 
{
	cout << name << ":" << date[0] << "." << date[1] << "." << date[2] << endl;
};
SingleEvent& SingleEvent::inputEventDetails() 
{
	cout << "Enter information about event: name, duration, date(day, month, year)" << endl;
	cin >> name >> duration >> date[0] >> date[1] >> date[2];
	return *this;
}
