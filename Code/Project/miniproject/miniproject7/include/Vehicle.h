#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class TrafficElement;

class Vehicle
{
protected:
    int id;
    string plate;
    int speed;

public:
    Vehicle(int id, const string &plate, int speed);
    virtual ~Vehicle();

    virtual bool canMove(const TrafficElement &element) const = 0;
    virtual void move();
    virtual void printStatus() const;

    int getSpeed() const;
    void setSpeed(int speed);

    bool operator<(const Vehicle &other) const;
    Vehicle &operator+(int speedtoadd);

    static int vehicleCount;
};
#endif