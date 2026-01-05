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
    ~Intersection();

    void addVehicle(Vehicle *vehicle);
    void deleteVehicle(int id);

    void evaluate();
    void printStatus() const;

    static int intersectionCount;
    static Intersection *activeIntersection;

};
#endif