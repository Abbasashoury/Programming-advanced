#include <string>
#include <vector>
#include "..\include\Resource.h"
#include "..\include\Timeinterval.h"
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
    void addInterval(const TimeInterval &T)
    {
        if (overlaps(T))
        {
        }
    }
    void hasConflict(const TimeInterval &) {}
    void printSchedule() {}
};