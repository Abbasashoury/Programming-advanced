#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <string>
#include <vector>
#include "Resource.h"

using std::string;
using std::vector;

class ResourceManager
{
private:
    vector<Resource> resources;
    static int totalResources;

public:
    int getResourceCount() const;
    Resource &getResource(int index);
    void addResource(int id, string name);
    bool hasConflict(const TimeInterval &other, int id);
    void searchResourceByName(const string &name);
    void printAllSchedules();
};
#endif