#ifndef SPEED_LIMIT_ZONE_H
#define SPEED_LIMIT_ZONE_H

#include "TrafficElement.h"

class SpeedLimitZone : public TrafficElement
{
private:
    int MAXSPEED;

public:
    SpeedLimitZone(int maxSpeed);
    ~SpeedLimitZone() override;

    bool allows(const Vehicle &vehicle) const override;
    void printRule() const override;
};
#endif