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
    bool hasConflict(const TimeInterval &other, int id);
    void searchResourceByName(const string &name);
    void printAllSchedules();
};
int ResourceManager::totalResources;
#endif