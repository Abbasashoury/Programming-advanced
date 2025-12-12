#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
#include <iostream>
using namespace std;

class Resource
{
private:
    int id;
    string name;
    vector<TimeInterval> intervals;

public:
    int getsize() { return intervals.size(); }
    TimeInterval getinterval(int j) { return intervals[j]; }
    void addInterval()
    {
        TimeInterval T;
        T.SetInterval();
        bool over;
        int i = 0;
        do
        {
            over = intervals[i].overlaps(T);
            if (over)
            {
                intervals.push_back(T);
                cout << "Interval added successfully." << endl;
                return;
            }
            else if (!over)
            {
                cout << "Interval overlaps with existing intervals. merge or cannot add." << endl;
                return;
            }
            i++;
        }while (i < intervals.size());
        
    }
    void hasConflict(const TimeInterval &) {}
    void printSchedule() {}
};
