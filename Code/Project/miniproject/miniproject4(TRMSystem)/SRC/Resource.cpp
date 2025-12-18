#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include "..\include\ResourceManager.h"
using namespace std;

Resource::Resource(int i, string n) : id(i), name(n) {}

int Resource::getsize() const { return intervals.size(); }
int Resource::getid() const { return id; }
string Resource::getName() const { return name; }
TimeInterval Resource::getinterval(int j) const { return intervals[j]; }

void Resource::addInterval(ResourceManager &mainManager, Time start, Time end)
{
    TimeInterval other(start, end);
    if (mainManager.hasConflict(other, this->id))
    {
        cout << "cannot add this interval due to conflict with other resources." << endl;
        return;
    }

    intervals.push_back(other);
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); ++i)
    {
        for (int j = i + 1; j < intervals.size();)
        {
            if (intervals[i].overlaps(intervals[j]) || intervals[i].getend() == intervals[j].getstart())
            {
                intervals[i] + intervals[j];
                intervals.erase(intervals.begin() + j);
                cout << "Merged overlapping intervals." << endl;
            }
            else
            {
                j++;
            }
        }
    }

    cout << "Interval added and merged successfully.\n";
}

void Resource::sortIntervals()
{
    sort(intervals.begin(), intervals.end());
}
void Resource::printSchedule()
{

    if (intervals.empty())
    {
        cout << "No intervals reserved.\n";
        return;
    }
    sortIntervals();

    for (int i = 0; i < intervals.size(); ++i)
    {
        cout << "[" << i + 1 << "]: ";

        intervals[i].getstart().print();
        cout << " to ";
        intervals[i].getend().print();
        cout << "\n";
    }
}