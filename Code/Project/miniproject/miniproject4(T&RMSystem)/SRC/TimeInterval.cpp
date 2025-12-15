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
    // TimeInterval merge() {}من کاربردی براش پیدا نکردم ولی چون نوشتیداضافه کردم
    bool overlaps(const TimeInterval &T) const
    {
        return (this->timestart < T.timeend) && (T.timestart < this->timeend);
    }

    TimeInterval operator+(const TimeInterval &other) const
    {
        if (!this->overlaps(other))
        {
            std::cout << "Warning: Cannot merge non-overlapping intervals." << std::endl;
            return *this;
        }

        const Time &newStart = (timestart < other.timestart) ? timestart : other.timestart;
        const Time &newEnd = (other.timeend < timeend) ? other.timeend : timeend;

        return TimeInterval(newStart, newEnd);
    }
    // bool operator<(const TimeInterval &other) const;
    // bool operator==(const Time &other) const;
};