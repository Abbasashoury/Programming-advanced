#include "..\include\Intersection.h"
#include "..\include\Car.h"
#include "..\include\Bus.h"
#include "..\include\EmergencyVehicle.h"
#include "..\include\TrafficLight.h"
#include "..\include\StopSign.h"
#include "..\include\SpeedLimitZone.h"

int main()
{
    Intersection intersection;

    Vehicle *car = new Car(1, "IR-111", 40);
    Vehicle *bus = new Bus(2, "IR-222", 30);
    Vehicle *emg = new EmergencyVehicle(3, "EMS-999", 80);

    TrafficElement *light = new TrafficLight(LightState::Red);
    TrafficElement *stop = new StopSign();
    TrafficElement *limit = new SpeedLimitZone(50);

    intersection.addVehicle(car);
    intersection.addVehicle(bus);
    intersection.addVehicle(emg);

    intersection.printStatus();
    cout << "---------------------------------" << endl;

    intersection.evaluate();
    cout << "---------------------------------" << endl;

    intersection.printStatus();

    delete light;
    delete stop;
    delete limit;
    delete car;
    delete bus;
    delete emg;

    return 0;
}