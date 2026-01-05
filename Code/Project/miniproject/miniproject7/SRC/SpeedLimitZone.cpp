#include "..\include\SpeedLimitZone.h"
#include "..\include\EmergencyVehicle.h"

SpeedLimitZone::SpeedLimitZone(int maxSpeed)
    : MAXSPEED(maxSpeed) {}

SpeedLimitZone::~SpeedLimitZone() {}

bool SpeedLimitZone::allows(const Vehicle &vehicle) const
{
    if (dynamic_cast<const EmergencyVehicle *>(&vehicle))
        return true;

    return vehicle.getSpeed() <= MAXSPEED;
}

void SpeedLimitZone::printRule() const
{
    cout << "SpeedLimitZone: max speed = " << MAXSPEED << endl;
}