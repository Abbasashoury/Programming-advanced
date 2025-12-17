#include "Time.h"
#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    Time()
    {
        cout << "enter the hour of start or end:\n";
        cin >> hour;
        cout << "enter the minuter of start or end:\n";
        cin >> minute;
    }
    int gethour() const { return hour; }
    int toMinutes() const { return 60 * hour + minute; }

    bool operator<(const Time &other) const
    {
        return this->toMinutes() < other.toMinutes();
    }
    bool operator>(const Time &other) const
    {
        return this->toMinutes() > other.toMinutes();
    }
    bool operator<=(const Time &other) const
    {
        return this->toMinutes() <= other.toMinutes();
    }
    int operator-(const Time &other) const
    {
        return this->toMinutes() - other.toMinutes();
    }
    bool operator==(const Time &other) const
    {
        return this->toMinutes() == other.toMinutes();
    }
};