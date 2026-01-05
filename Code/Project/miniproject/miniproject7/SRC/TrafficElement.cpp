#include "..\include\TrafficElement.h"
#include <iostream>
using namespace std;

TrafficElement::~TrafficElement() {}

void TrafficElement::printRule() const
{
    cout << "Generic traffic rule" << endl;
}