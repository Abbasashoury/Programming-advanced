#include "..\include\TrafficLight.h"
#include "..\include\EmergencyVehicle.h"

TrafficLight::TrafficLight(LightState state)
    : STATE(state) {}

TrafficLight::~TrafficLight() {}

bool TrafficLight::allows(const Vehicle &vehicle) const
{
    if (STATE == LightState::Green)
        return true;

    if (STATE == LightState::Red)
        return dynamic_cast<const EmergencyVehicle *>(&vehicle) != nullptr;

    return false;
}

void TrafficLight::printRule() const
{
    cout << "TrafficLight rule: Emergencyvehicles can pass on Red, all vehicles can pass on Green." << endl;
}

bool TrafficLight::operator==(LightState state) const
{
    return STATE == state;
}