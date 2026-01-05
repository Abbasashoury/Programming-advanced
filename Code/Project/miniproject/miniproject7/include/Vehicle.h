#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include "Intersection.h"
using namespace std;

class TrafficElement;

class Vehicle
{
protected:
    int ID;
    string PLATE;
    int SPEED;

public:
    Vehicle(int id, const string &plate, int speed);
    virtual ~Vehicle();

    virtual bool canMove(const TrafficElement &element) const = 0;
    virtual void move();
    void printStatus() const;

    int getSpeed() const;
    void setSpeed(int speed);
    int getId() const;
    
    bool operator<(const Vehicle &other) const;
    Vehicle &operator+(int speedtoadd);

    static int vehicleCount;
};
#endif