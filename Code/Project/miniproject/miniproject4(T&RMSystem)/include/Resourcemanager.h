#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <string>
#include <vector>
#include "Resource.h"

class ResourceManager
{
private:
    vector<Resource> resources;
    static int totalResources;

public:
    void addResource();
    void hasConflict(const TimeInterval &,int);
    void searchResourceByName(const string &);
    void printAllSchedules();
};
int ResourceManager::totalResources;
#endif