#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(int id, const string &plate, int speed);

    bool canMove(const TrafficElement &element) const override;
    void move() override;
};
#endif