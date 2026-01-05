#include "..\include\StopSign.h"
#include "..\include\EmergencyVehicle.h"

StopSign::StopSign() {}
StopSign::~StopSign() {}

bool StopSign::allows(const Vehicle &vehicle) const
{
    if (dynamic_cast<const EmergencyVehicle *>(&vehicle))
        return true;

    return vehicle.getSpeed() == 0;
}

void StopSign::printRule() const
{
    cout << "StopSign: All vehicles except emergency vehicles must stop." << endl;
}