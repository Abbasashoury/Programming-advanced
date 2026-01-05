#include "..\include\Car.h"
#include "..\include\TrafficElement.h"

Car::Car(int id, const string &plate, int speed)
    : Vehicle(id, plate, speed) {}

Car::~Car() {}

bool Car::canMove(const TrafficElement &element) const
{
    return element.allows(*this);
}

void Car::move()
{
    SPEED += 5;
    cout << "Car moves. New speed: " << SPEED << endl;

    Vehicle::move();
}