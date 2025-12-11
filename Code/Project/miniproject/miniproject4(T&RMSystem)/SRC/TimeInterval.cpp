#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include "..\include\Resource.h"
#include <iostream>
#include <vector>
using namespace std;

class TimeInterval
{
private:
    Time timestart;
    Time timeend;

public:
    TimeInterval(int TS = 0, int TE = 0) : timestart(TS), timeend(TE) {}
    Time getstart(int j) { return timestart[j]; }
    Time getend(int j) { return timeend[j]; }
    bool overlaps(const TimeInterval &T)
    {
        for (int i = 0; i < Resource.getsize(); i++)
        {
            if (this->timestart == T.timestart && this->timeend == T.timeend)
            {
                cout << "full overlap";
                return false;
            }
            else if (this->timestart == T.timestart)
            {
                cout << "partial overlap";


                return false;
            }
            else if (this->timeend == T.timeend)
            {
                cout << "partial overlap";

                return false;
            }
            cout << "no overlap";
            return true;
        }
    }
    int duration() {}
    TimeInterval merge(const TimeInterval &) {} // من کاربردی براش پیدا نکردم ولی چون نوشتیداضافه کردم
    bool operator+(const TimeInterval &other) const
    {
    }
    bool operator<(const TimeInterval &other) const
    {
    }
    bool operator==(const Time &other) const
    {
        if(this->gethour() == other.gethour() && this->toMinutes() == other.toMinutes())
            return true;
        else
            return false;
    }
};