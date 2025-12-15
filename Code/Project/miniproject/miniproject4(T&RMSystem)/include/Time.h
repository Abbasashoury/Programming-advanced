#ifndef TIME_H
#define TIME_H
#include "Time.h"
#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    Time();
    int gethour() const;
    int toMinutes() const;

    bool operator<(const Time &other) const;
    bool operator<=(const Time &other) const;
    int operator-(const Time &other) const;
};
#endif