#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
using namespace std;

#include "Vehicle.h"
#include "TrafficElement.h"

class Intersection
{
private:
    vector<Vehicle *> vehicles;
    vector<TrafficElement *> rules;

public:
    Intersection();

    void addVehicle(Vehicle *vehicle);
    void addRule(TrafficElement *rule);

    void evaluate();
    void printStatus() const;

    static int intersectionCount;
};
#endif