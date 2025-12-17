#include <iostream>
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\ResourceManager.h"
using namespace std;

class ResourceManager
{
private:
    vector<Resource> resources;
    static int totalResources;

public:
    void addResource()
    {
        int id;
        string name;
        cout << "Enter resource id: ";
        cin >> id;
        cout << "Enter resource name: ";
        cin >> name;
        Resource newResource(id, name);
        resources.push_back(newResource);
        totalResources++;
    }
    bool hasConflict(const TimeInterval &other, int id) // اینو اینجا من نوشتم که بره تمام تداخل بین بازع=ه های منابع مختلف رو پیدا کنه و نزاره یه کلاس درس توی یه ساعت توسط دونفر رزرو بشه
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
                    cout << "Conflict detected with resource ID: " << i << endl;
                    return true;
                }
            }
        }
        cout << "No conflicts detected" << endl;
        return false;
    }
    void searchResourceByName(const string &) {}
    void printAllSchedules() {}
};
int ResourceManager::totalResources = 0;