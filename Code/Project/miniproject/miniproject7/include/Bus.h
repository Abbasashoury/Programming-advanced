#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle
{
public:
    Bus(int id, const string &plate, int speed);
    ~Bus() override;

    bool canMove(const TrafficElement &element) const override;
    void move() override;
};
#endif