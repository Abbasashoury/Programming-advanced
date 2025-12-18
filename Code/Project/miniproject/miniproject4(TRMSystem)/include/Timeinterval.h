#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H
#include "Time.h"

class TimeInterval
{
private:
    Time timestart;
    Time timeend;

public:
    TimeInterval(Time ts, Time te);
    Time getstart() const;
    Time getend() const;

    int duration();
    bool overlaps(const TimeInterval &other) const;
    void operator+(const TimeInterval &other);
    bool operator<(const TimeInterval &other) const;
    bool operator==(const TimeInterval &other) const;
};
#endif