#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

class TimeInterval
{
private:
    int timestart;
    int timeend;

public:
    TimeInterval();
    Time getstart();
    Time getend();
    void SetInterval();
    bool overlaps(const TimeInterval &T);

    int duration();
    TimeInterval merge(const TimeInterval &);
    bool operator+(const TimeInterval &other) const;
    bool operator<(const TimeInterval &other) const;
    bool operator==(const Time &other) const;
};
#endif