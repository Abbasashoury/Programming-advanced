#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include <iostream>
#include <vector>
using namespace std;

class TimeInterval
{
private:
    Time timestart;
    Time timeend;

public:
    TimeInterval(Time ts, Time te) : timestart(ts), timeend(te) {}
    Time getstart() const { return timestart; }
    Time getend() const { return timeend; }
    int duration()
    {
        return timeend - timestart;
    }
    // TimeInterval merge() {}  من کاربردی براش پیدا نکردم چون عملگر + رو داریم ولی چون نوشتیداضافه کردم
    bool overlaps(const TimeInterval &T) const
    {
        return (this->timestart < T.timeend) && (T.timestart < this->timeend);
    }

    void operator+(const TimeInterval &other)
    {

        const Time &newstart = (timestart < other.timestart) ? timestart : other.timestart;
        const Time &newend = (timeend > other.timeend) ? timeend : other.timeend;

        timestart = newstart;
        timeend = newend;
    }
    // من کاربردی براش پیدا نکردم ولی چون نوشتیداضافه کردم
    // bool operator<(const TimeInterval &other) const;
    // bool operator==(const Time &other) const;
};