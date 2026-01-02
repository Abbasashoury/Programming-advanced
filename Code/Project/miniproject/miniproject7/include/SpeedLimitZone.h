#ifndef SPEED_LIMIT_ZONE_H
#define SPEED_LIMIT_ZONE_H

#include "TrafficElement.h"

class SpeedLimitZone : public TrafficElement
{
private:
    int maxSpeed;

public:
    SpeedLimitZone(int maxSpeed);

    bool allows(const Vehicle &vehicle) const override;
    void printRule() const override;
};
#endif