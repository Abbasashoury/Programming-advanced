#ifndef TRAFFIC_ELEMENT_H
#define TRAFFIC_ELEMENT_H

class Vehicle;

class TrafficElement
{
public:
    virtual ~TrafficElement();

    virtual bool allows(const Vehicle &vehicle) const = 0;
    virtual void printRule() const;
};
#endif