#include "LandingGearSensor.h"
#include "LandingGearCheckStrategy.h"

LandingGearSensor::LandingGearSensor(const std::string& id)                    // Landing gear has no numeric range (min/max are unused, so 0.0).
    : AircraftComponent(id, Limits{ 0.0, 0.0, {"UP", "DOWN", "IN TRANSIT"} },  // uses the validStates part of Limits: only valid positions are "UP", "DOWN" and "IN TRANSIT".
		std::make_unique<LandingGearCheckStrategy>()) {                        // landing gear specific strategy is created and passed to the base class constructor.
}

std::string LandingGearSensor::interpretReading() const {
	return "Position: " + std::get<std::string>(getCurrentReading());          // describes the reading itself, the check result comes from the strategy.
}