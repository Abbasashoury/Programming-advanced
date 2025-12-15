#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H

class TimeInterval
{
private:
    int timestart;
    int timeend;

public:
    TimeInterval(Time ts, Time te);
    Time getstart() const;
    Time getend() const;

    bool overlaps(const TimeInterval &T) const;
    int duration();
    // TimeInterval merge() {}من کاربردی براش پیدا نکردم ولی چون نوشتیداضافه کردم

    TimeInterval operator+(const TimeInterval &other) const;
    // bool operator<(const TimeInterval &other) const;
    // bool operator==(const Time &other) const;
};
#endif