#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"

class ResourceManager;
class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    Resource(int i, string n);
    int getsize();
    int getid();
    string Resource::getName();
    TimeInterval getinterval(int j);

    void addInterval(ResourceManager &);
    void printSchedule();
};

#endif