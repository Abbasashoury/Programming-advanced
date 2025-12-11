#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    Time(int h = 0, int m = 0) : hour(h), minute(m) {}

    int toHour() const { return hour; }
    int toMinutes() const { return minute; }

    bool operator<(const Time &other) const
    {
        return this->toMinutes() < other.toMinutes();
    }
    bool operator==(const Time &other) const
    {
        return this->toHour() == other.toHour() && this->toMinutes() == other.toMinutes();
    }
    bool operator-(const Time &other) const
    {
        return this->toMinutes() - other.toMinutes();
    }
};
class TimeEnterval
{
private:
public:
};
class Resource
{
private:
public:
};
class ResourceManager
{
private:
public:
};

int main()
{

    return 0;
}