#include "Vehicle.h"
using namespace std;

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(int id, const string &plate, int speed) {}
Vehicle::~Vehicle() {}

void Vehicle::move() {}
void Vehicle::printStatus() const {}

int Vehicle::getSpeed() const { return 0; }
void Vehicle::setSpeed(int speed) {}

bool Vehicle::operator<(const Vehicle &other) const { return false; }
Vehicle &Vehicle::operator+(int speedtoadd) { return *this; }
