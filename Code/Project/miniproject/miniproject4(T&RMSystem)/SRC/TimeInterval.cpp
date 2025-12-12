#include "..\include\Timeinterval.h"
#include "..\include\Time.h"
#include <iostream>
#include <vector>
using namespace std;

class TimeInterval
{
private:
    Time timestart;
    Time timeend;

public:
    Time getstart() { return timestart; }
    Time getend() { return timeend; }
    void SetInterval()
    {
        int hourstart, minutestart, hourend, minuteend;
        cout << "enter the TimeStart hour:\n";
        cin >> hourstart;
        cout << "enter the TimeEnd hour:\n";
        cin >> hourend;
        cout << "enter the TimeStart minute:\n";
        cin >> minutestart;
        cout << "enter the TimeEnd minute:\n";
        cin >> minuteend;

        timestart.SetTime(hourstart, minutestart); // شاید عملگر انتساب لازم باشه
        timeend.SetTime(hourend, minuteend);
    }
    bool overlaps(const TimeInterval &T)
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
        if (this->gethour() == other.gethour() && this->toMinutes() == other.toMinutes())
            return true;
        else
            return false;
    }
};