#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;

public:
    Time(int h, int m);
    int gethour() const;
    int toMinutes() const;
    void print() const;

    bool operator<(const Time &) const;
    bool operator>(const Time &) const;
    bool operator<=(const Time &) const;
    int operator-(const Time &) const;
    bool operator==(const Time &) const;
};

#endif