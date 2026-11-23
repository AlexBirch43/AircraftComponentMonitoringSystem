#include "MaintenancePanelAlert.h"
#include <iostream>

void MaintenancePanelAlert::send(const Alert& alert) const {
	std::cout << "[MAINTENANCE PANEL ALERT] - " << alert.componentId << ": " << alert.message << '\n';  // prints labelled maintenance alert to the console
}