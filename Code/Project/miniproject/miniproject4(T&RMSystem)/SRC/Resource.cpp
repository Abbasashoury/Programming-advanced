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
    void addInterval(const TimeInterval &) {}
    void hasConflict(const TimeInterval &) {}
    void printSchedule() {}
};