#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include "..\include\ResourceManager.h"

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
    TimeInterval getinterval();
    
    void addInterval(ResourceManager &);
    void printSchedule();
};

#endif