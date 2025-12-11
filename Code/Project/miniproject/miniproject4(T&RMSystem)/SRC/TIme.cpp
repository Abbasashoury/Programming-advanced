#include "Time.h"

class Time
{
private:
    int hour;
    int minute;

public:
    Time::Time(int h = 0, int m = 0) : hour(h), minute(m) {}

    int Time::gethour() const { return hour; }
    int Time::toMinutes() const { return 60 * hour + minute; }

    bool Time::operator>(const Time &other) const
    {
        return this->toMinutes() > other.toMinutes();
    }
    bool Time::operator==(const Time &other) const
    {
        return this->gethour() == other.gethour() && this->toMinutes() == other.toMinutes();
    }
    int Time::operator-(const Time &other) const
    {
        return this->toMinutes() - other.toMinutes();
    }
};