#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "TrafficElement.h"

enum class LightState
{
    Red,
    Yellow,
    Green
};

class TrafficLight : public TrafficElement
{
private:
    LightState STATE;

public:
    TrafficLight(LightState state);
    ~TrafficLight() override;

    bool allows(const Vehicle &vehicle) const override;
    void printRule() const override;

    bool operator==(LightState state) const;
};
#endif