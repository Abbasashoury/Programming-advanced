#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>
#include "Timeinterval.h"

class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    int getsize();
    TimeInterval getinterval();
    void addInterval(const TimeInterval &);
    void hasConflict(const TimeInterval &);
    void printSchedule();
};

#endif