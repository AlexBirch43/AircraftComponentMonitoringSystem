#include <iostream>
#include <memory>
#include "PressureSensor.h"
#include "TemperatureSensor.h"
#include "LandingGearSensor.h"
#include "ComponentRepository.h"


int main() {
    ComponentRepository repository;

    repository.addComponent(std::make_unique<PressureSensor>("Hydraulic Pump Sensor 1"));
    repository.addComponent(std::make_unique<TemperatureSensor>("Engine Temperature Sensor 1"));
    repository.addComponent(std::make_unique<LandingGearSensor>("Landing Gear Sensor 1"));

	// tests for normal readings
    std::cout << "Normal readings\n";
    repository.findComponent("Hydraulic Pump Sensor 1")->updateReading(50.0);
    repository.findComponent("Engine Temperature Sensor 1")->updateReading(25.0);
    repository.findComponent("Landing Gear Sensor 1")->updateReading("DOWN");

    for (const auto& component : repository.getAll()) {
        component->displayStatus();
    }

	// tests for out of range readings
	std::cout << "\nOut of range readings\n";
    repository.findComponent("Hydraulic Pump Sensor 1")->updateReading(150.0);
    repository.findComponent("Engine Temperature Sensor 1")->updateReading(-25.0);
    repository.findComponent("Landing Gear Sensor 1")->updateReading("JAMMED");

    for (const auto& component : repository.getAll()) {
        component->displayStatus();
    }

	// tests for edge cases and case sensitivity
	std::cout << "\nEdge case and case sensitive readings\n";
    repository.findComponent("Hydraulic Pump Sensor 1")->updateReading(0.0);
    repository.findComponent("Engine Temperature Sensor 1")->updateReading(1000.0);
    repository.findComponent("Landing Gear Sensor 1")->updateReading("in transit");

    for (const auto& component : repository.getAll()) {
        component->displayStatus();
    }


	// tests for repository operations
	std::cout << "\nRepository tests\n";
	bool added = repository.addComponent(std::make_unique<PressureSensor>("Hydraulic Pump Sensor 1"));   // test to add a duplicate ID
    std::cout << "Add duplicate ID: " << (added ? "ID added" : "ID rejected") << '\n';

	bool found = repository.findComponent("Engine Temperature Sensor 2") != nullptr;              // test to find a non-existent component
    std::cout << "Find missing ID: " << (found ? "ID found" : "ID not found") << '\n';

	bool removed = repository.removeComponent("Landing Gear Sensor 1");                           // test to remove an existing component
    std::cout << "Remove existing ID: " << (removed ? "ID removed" : "ID not found") << '\n';

	removed = repository.removeComponent("Landing Gear Sensor 1");                                // test to remove the same component again
    std::cout << "Remove again: " << (removed ? "ID removed" : "ID not found") << '\n';

	std::cout << "Components remaining: " << repository.getAll().size() << '\n';                  // test for  remaining components

    return 0;
}









