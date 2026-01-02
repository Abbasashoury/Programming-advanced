#include "SpeedLimitZone.h"

SpeedLimitZone::SpeedLimitZone(int maxSpeed) {}

bool SpeedLimitZone::allows(const Vehicle &vehicle) const { return false; }
void SpeedLimitZone::printRule() const {}