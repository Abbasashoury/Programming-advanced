#include "EmergencyVehicle.h"

EmergencyVehicle::EmergencyVehicle(int id, const string &plate, int speed)
    : Vehicle(id, plate, speed) {}

bool EmergencyVehicle::canMove(const TrafficElement &element) const { return false; }
void EmergencyVehicle::move() {}