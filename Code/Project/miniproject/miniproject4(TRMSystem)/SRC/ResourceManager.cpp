#include <iostream>
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\ResourceManager.h"
using namespace std;

int ResourceManager::totalResources = 0;

int ResourceManager::getResourceCount() const
{
    return resources.size();
}
Resource &ResourceManager::getResource(int index)
{
    return resources[index];
}
bool ResourceManager::checkid(int id) const
{
    for (int i = 0; i < resources.size(); ++i)
    {
        if (resources[i].getid() == id)
            return true;
    }
    return false;
}

bool ResourceManager::checkname(const string &name) const
{
    for (int i = 0; i < resources.size(); ++i)
    {
        if (resources[i].getName() == name)
            return true;
    }
    return false;
}

void ResourceManager::addResource(int id, string name)
{
    if (checkid(id))
    {
        cout << "Error: Resource with this ID already exists.\n";
        return;
    }

    if (checkname(name))
    {
        cout << "Error: Resource with this name already exists.\n";
        return;
    }
    Resource newResource(id, name);
    resources.push_back(newResource);
    totalResources++;
}
bool ResourceManager::hasConflict(const TimeInterval &other, int id)
{
    for (int i = 0; i < resources.size(); ++i)
    {
        if (resources[i].getid() == id)
            continue;
        Resource &res = resources[i];
        for (int j = 0; j < res.getsize(); ++j)
        {
            TimeInterval temp = res.getinterval(j);
            if (temp.overlaps(other))
            {
                cout << "Conflict detected with resource ID: " << resources[i].getid() << endl;
                return true;
            }
        }
    }
    cout << "No conflicts detected" << endl;
    return false;
}
void ResourceManager::searchResourceByName(const string &name)
{
    for (int i = 0; i < resources.size(); ++i)
    {
        Resource &res = resources[i];

        if (res.getName() == name)
        {
            cout << "Resource found:\n";
            cout << "ID: " << res.getid() << "\n";
            cout << "Name: " << name << "\n";
            res.printSchedule();
            return;
        }
    }
    cout << "Resource not found.\n";
}
void ResourceManager::printAllSchedules()
{
    cout << "===========================================\n";
    cout << "Total Resources: " << totalResources << "\n";

    for (int i = 0; i < resources.size(); ++i)
    {
        cout << "-------------------------------------------\n";
        cout << "Resource #" << i + 1 << "\n";
        cout << "ID   : " << resources[i].getid() << "\n";
        cout << "Name : " << resources[i].getName() << "\n";

        resources[i].printSchedule();
        cout << "\n";
    }

    cout << "===========================================\n";
}