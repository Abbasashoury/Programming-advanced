#include "TrafficLight.h"

TrafficLight::TrafficLight(LightState state) {}

bool TrafficLight::allows(const Vehicle &vehicle) const { return false; }
void TrafficLight::printRule() const {}

bool TrafficLight::operator==(LightState state) const { return false; }