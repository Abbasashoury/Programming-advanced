#include "..\include\Intersection.h"

int Intersection::intersectionCount = 0;
Intersection *Intersection::activeIntersection = nullptr;

Intersection::Intersection()
{
    intersectionCount++;
    activeIntersection = this;
}

Intersection::~Intersection()
{
    intersectionCount--;
}

void Intersection::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

void Intersection::deleteVehicle(int id)
{
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            delete *it;
            vehicles.erase(it);
            return;
        }
    }
}

void Intersection::evaluate()
{
    for (Vehicle *v : vehicles)
    {
        bool allowed = true;

        for (TrafficElement *r : rules)
        {
            if (!v->canMove(*r))
            {
                allowed = false;
                break;
            }
        }

        if (allowed)
            v->move();
        else
            cout << "Vehicle blocked by traffic rules" << endl;
    }
}

void Intersection::printStatus() const
{
    cout << "=====================================" << endl;

    cout << "Number of vehicles: " << vehicles.size() << endl;

    if (vehicles.size() == 0)
        cout << "Traffic level: empty" << endl;
    else if (vehicles.size() <= 4)
        cout << "Traffic level: normal" << endl;
    else
        cout << "Traffic level: heavy" << endl;
}