#include "..\include\Bus.h"
#include "..\include\TrafficElement.h"

Bus::Bus(int id, const string &plate, int speed)
    : Vehicle(id, plate, speed) {}

Bus::~Bus() {}

bool Bus::canMove(const TrafficElement &element) const
{
    return element.allows(*this);
}

void Bus::move()
{
    SPEED += 2;
    cout << "Bus moves. New speed: " << SPEED << endl;

    Vehicle::move();
}