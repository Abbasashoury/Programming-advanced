#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

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
    bool overlaps(const TimeInterval &T) const;
    void operator+(const TimeInterval &other);

};
#endif