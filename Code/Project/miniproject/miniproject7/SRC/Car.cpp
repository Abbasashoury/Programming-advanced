#include "Car.h"

Car::Car(int id, const string &plate, int speed)
    : Vehicle(id, plate, speed) {}

bool Car::canMove(const TrafficElement &element) const { return false; }
void Car::move() {}