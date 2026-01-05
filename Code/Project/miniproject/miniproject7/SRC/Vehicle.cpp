#include "..\include\Vehicle.h"

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(int id, const string &plate, int speed)
    : ID(id), PLATE(plate), SPEED(speed)
{
    vehicleCount++;
}

Vehicle::~Vehicle()
{
    vehicleCount--;
}

void Vehicle::move()
{
    cout << "Vehicle " << ID << " moved and left intersection" << endl;

    if (Intersection::activeIntersection)
        Intersection::activeIntersection->deleteVehicle(ID);
}

void Vehicle::printStatus() const
{
    cout << "ID: " << ID
         << " | Plate: " << PLATE
         << " | Speed: " << SPEED << endl;
}

int Vehicle::getSpeed() const
{
    return SPEED;
}

void Vehicle::setSpeed(int speed)
{
    SPEED = speed;
}
int Vehicle::getId() const
{
    return ID;
}

bool Vehicle::operator<(const Vehicle &other) const
{
    return SPEED < other.SPEED;
}

Vehicle &Vehicle::operator+(int speedtoadd)
{
    SPEED += speedtoadd;
    if (SPEED < 0)
        SPEED = 0;
    return *this;
}