#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include <iostream>
#include <vector>
using namespace std;

TimeInterval::TimeInterval(Time ts, Time te) : timestart(ts), timeend(te) {}
Time TimeInterval::getstart() const { return timestart; }
Time TimeInterval::getend() const { return timeend; }
int TimeInterval::duration()
{
    return timeend - timestart;
}
bool TimeInterval::overlaps(const TimeInterval &T) const
{
    return (this->timestart < T.timeend) && (T.timestart < this->timeend);
}

void TimeInterval::operator+(const TimeInterval &other)
{

    const Time &newstart = (timestart < other.timestart) ? timestart : other.timestart;
    const Time &newend = (timeend > other.timeend) ? timeend : other.timeend;

    timestart = newstart;
    timeend = newend;
}