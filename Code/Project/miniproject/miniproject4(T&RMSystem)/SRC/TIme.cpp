#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
    cout << "enter the hour of start or end:\n";
    cin >> hour;
    cout << "enter the minuter of start or end:\n";
    cin >> minute;
}
int Time::gethour() const { return hour; }
int Time::toMinutes() const { return 60 * hour + minute; }
void Time::print() const
{
    if (hour < 10)
    {
        cout << '0'
    };
    cout << hour << ":";
    if (minute < 10)
    {
        cout << '0'
    };
    cout << minute;
}

bool Time::operator<(const Time &other) const
{
    return this->toMinutes() < other.toMinutes();
}
bool Time::operator>(const Time &other) const
{
    return this->toMinutes() > other.toMinutes();
}
bool Time::operator<=(const Time &other) const
{
    return this->toMinutes() <= other.toMinutes();
}
int Time::operator-(const Time &other) const
{
    return this->toMinutes() - other.toMinutes();
}
bool Time::operator==(const Time &other) const
{
    return this->toMinutes() == other.toMinutes();
}