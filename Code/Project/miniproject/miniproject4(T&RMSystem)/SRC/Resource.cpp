#include <iostream>
#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include "..\include\ResourceManager.h"
using namespace std;

class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    Resource(int i, string n) : id(i), name(n) {}
    int getsize() { return intervals.size(); }
    int getid() { return id; }
    TimeInterval getinterval(int j) { return intervals[j]; }
    void addInterval(ResourceManager &mainManager)
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

    void printSchedule() {}
};