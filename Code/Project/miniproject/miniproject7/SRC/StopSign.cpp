#include "StopSign.h"

StopSign::StopSign() {}

bool StopSign::allows(const Vehicle &vehicle) const { return false; }
void StopSign::printRule() const {}