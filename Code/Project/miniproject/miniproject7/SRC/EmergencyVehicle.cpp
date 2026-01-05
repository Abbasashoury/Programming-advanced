#include "..\include\EmergencyVehicle.h"
#include "..\include\TrafficElement.h"

EmergencyVehicle::EmergencyVehicle(int id, const string &plate, int speed)
    : Vehicle(id, plate, speed) {}

EmergencyVehicle::~EmergencyVehicle() {}

bool EmergencyVehicle::canMove(const TrafficElement &element) const
{
    return element.allows(*this);
}

void EmergencyVehicle::move()
{
    SPEED += 10;
    cout << "Emergency vehicle moves. New speed: " << SPEED << endl;

    Vehicle::move();
}