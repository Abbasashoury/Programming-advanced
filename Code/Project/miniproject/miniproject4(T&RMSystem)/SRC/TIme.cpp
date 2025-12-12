#include "Time.h"

class Time
{
private:
    int hour;
    int minute;

public:
    Time();

    int gethour() const { return hour; }
    int toMinutes() const { return 60 * hour + minute; }
    void SetTime(int h, int m)
    {
        hour = h;
        minute = m;
    }

    bool operator>(const Time &other) const
    {
        return this->toMinutes() > other.toMinutes();
    }
    bool operator==(const Time &other) const
    {
        return this->toMinutes() == other.toMinutes();
    }
    int operator-(const Time &other) const
    {
        return this->toMinutes() - other.toMinutes();
    }
};