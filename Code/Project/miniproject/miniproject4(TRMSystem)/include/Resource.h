#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"

using std::string;
using std::vector;

class ResourceManager;
class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    Resource(int i, string n);
    int getsize() const;
    int getid() const;
    string getName() const;
    TimeInterval getinterval(int j) const;

    void addInterval(ResourceManager &mainManager, Time start, Time end);
    void sortIntervals();
    void printSchedule();
};

#endif