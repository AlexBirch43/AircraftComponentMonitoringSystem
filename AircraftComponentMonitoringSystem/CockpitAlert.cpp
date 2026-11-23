#include "CockpitAlert.h"
#include <iostream>

void CockpitAlert::send(const Alert& alert) const {
	std::cout << "[COCKPIT ALERT] - " << alert.componentId << ": " << alert.message << '\n';  // prints labelled cockpit alert to the console
}