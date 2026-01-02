#ifndef EMERGENCY_VEHICLE_H
#define EMERGENCY_VEHICLE_H

#include "Vehicle.h"

class EmergencyVehicle : public Vehicle
{
public:
    EmergencyVehicle(int id, const string &plate, int speed);

    bool canMove(const TrafficElement &element) const override;
    void move() override;
};
#endif