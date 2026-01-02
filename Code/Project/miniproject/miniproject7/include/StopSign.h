#ifndef STOP_SIGN_H
#define STOP_SIGN_H

#include "TrafficElement.h"

class StopSign : public TrafficElement
{
public:
    StopSign();

    bool allows(const Vehicle &vehicle) const override;
    void printRule() const override;
};
#endif