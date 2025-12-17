#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;

public:
    Time();
    int gethour() const;
    int toMinutes() const;
    void Time::print() const;

    bool operator<(const Time &) const;
    bool operator>(const Time &) const;
    bool operator<=(const Time &) const;
    int operator-(const Time &) const;
    bool operator==(const Time &) const;
};

#endif