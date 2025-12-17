#include <iostream>
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include "..\include\ResourceManager.h"
using namespace std;

Resource::Resource(int i, string n) : id(i), name(n) {}

int Resource::getsize() { return intervals.size(); }
int Resource::getid() { return id; }
string Resource::getName() { return name; }
TimeInterval Resource::getinterval(int j) { return intervals[j]; }

void Resource::addInterval(ResourceManager &mainManager)
{
    Time start;
    Time end;
    TimeInterval other(start, end);
    if (mainManager.hasConflict(other, this->id))
    {
        cout << "cannot add this interval due to conflict with other resources." << endl;
        return;
    }

    for (int i = 0; i < intervals.size(); ++i)
    {
        TimeInterval &temp = intervals[i];

        if (temp.overlaps(other))
        {
            temp + other;
            cout << "Interval overlaps with existing intervals. cannot add." << endl;
            return;
        }
    }

    intervals.push_back(other);
    cout << "Interval added successfully." << endl;
}

void Resource::printSchedule()
{

    if (intervals.empty())
    {
        cout << "No intervals reserved.\n";
        return;
    }

    for (int i = 0; i < intervals.size(); ++i)
    {
        cout << "[" << i + 1 << "]: ";

        intervals[i].getstart().print();
        cout << " to ";
        intervals[i].getend().print();
        cout << "\n";
    }
}