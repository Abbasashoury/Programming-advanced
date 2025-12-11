#include "..\include\Timeinterval.h"

class TimeInterval
{
private:
    int timestart;
    int timeend;

public:
    bool overlaps(const TimeInterval &) {}
    int duration() {}
    TimeInterval merge(const TimeInterval &) {}
    bool operator+(const TimeInterval &other) const {}
    bool operator<(const TimeInterval &other) const {}
    bool operator==(const TimeInterval &other) const {}
};