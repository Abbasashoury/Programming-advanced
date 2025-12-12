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
    void SetTime(int h, int m);

    bool operator>(const Time &other) const;
    bool operator==(const Time &other) const;
    int operator-(const Time &other) const;
};
#endif