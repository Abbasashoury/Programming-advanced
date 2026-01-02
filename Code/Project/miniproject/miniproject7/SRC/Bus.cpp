#include "Bus.h"

Bus::Bus(int id, const string& plate, int speed)
    : Vehicle(id, plate, speed) {}

bool Bus::canMove(const TrafficElement& element) const { return false; }
void Bus::move() {}