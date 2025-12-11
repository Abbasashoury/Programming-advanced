#include <iostream>
#include <vector>

using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    Time(int h = 0, int m = 0) : hour(h), minute(m) {}

    int gethour() const { return hour; }
    int toMinutes() const { return 60 * hour + minute; }

    bool operator>(const Time &other) const
    {
        return this->toMinutes() > other.toMinutes();
    }
    bool operator==(const Time &other) const
    {
        return this->gethour() == other.gethour() && this->toMinutes() == other.toMinutes();
    }
    int operator-(const Time &other) const
    {
        return this->toMinutes() - other.toMinutes();
    }
};
class TimeInterval
{
private:
    int timestart;
    int timeend;

public:
    bool overlaps(const TimeInterval &) {}
    int duration() {}
    TimeInterval merge(const TimeInterval &) {}
    bool operator+(const TimeInterval &other) const {}
    bool operator<(const TimeInterval &other) const {}
    bool operator==(const TimeInterval &other) const {}
};
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
class ResourceManager
{
private:
    vector<Resource> resources;
    static int totalResources;

public:
    void addResource(const Resource &) {}
    void searchResourceByName(const string &) {}
    void printAllSchedules() {}
};

int main()
{

    return 0;
}