#include <iostream>
#include <memory>
#include "PressureSensor.h"
#include "TemperatureSensor.h"
#include "LandingGearSensor.h"
#include "ComponentRepository.h"
#include "Alert.h"
#include "CockpitAlert.h"
#include "MaintenancePanelAlert.h"
#include "AlertService.h"

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


	//tests for alert channels
	std::cout << "\nAlert channel tests\n";
	Alert testAlert{ "Test component 1", "Test Alert!" };    // create test alert with a test ID and message

	CockpitAlert cockpit;                          // create cockpit delivery method
	MaintenancePanelAlert maintenancePanel;        // create maintenance panel delivery method
	cockpit.send(testAlert);                      // send test alert to the cockpit
	maintenancePanel.send(testAlert);             // send test alert to the maintenance panel

    std::cout << "Same alert via the interface\n";
    const IAlertChannel* channels[] = { &cockpit, &maintenancePanel };   // list both channels as the interface type
    for (const IAlertChannel* channel : channels) {                      // go through each channel in turn
        channel->send(testAlert);                                        // each channel delivers the alert its own way
    }

    // tests for the alertservice
    std::cout << "\nAlert service tests\n";
    AlertService alertService;                                                        // create the service (starts with no channels)

    std::cout << "Send without channels (expect no output):";
    alertService.sendAlert(testAlert);                                                // test sending with an empty service
    std::cout << "(Nothing sent)\n";

    bool addedChannel = alertService.addChannel(nullptr);                             // test adding a null channel
    std::cout << "Add null channel: " << (addedChannel ? "channel added" : "channel rejected") << '\n';

    addedChannel = alertService.addChannel(std::make_unique<CockpitAlert>());         // test adding the first channel
    std::cout << "Add cockpit channel: " << (addedChannel ? "channel added" : "channel rejected") << '\n';
    alertService.sendAlert(testAlert);

    addedChannel = alertService.addChannel(std::make_unique<MaintenancePanelAlert>());   // test adding the second channel
    std::cout << "Add maintenance panel channel: " << (addedChannel ? "channel added" : "channel rejected") << '\n';
    alertService.sendAlert(testAlert);

    return 0;
}









