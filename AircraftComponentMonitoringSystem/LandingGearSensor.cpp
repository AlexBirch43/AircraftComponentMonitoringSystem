#include "LandingGearSensor.h"
#include <algorithm>   // for std::find

LandingGearSensor::LandingGearSensor(const std::string& id)                      // Landing gear has no numeric range (min/max are unused, so 0.0).
    : AircraftComponent(id, Limits{ 0.0, 0.0, {"UP", "DOWN", "IN TRANSIT"} }) {  // uses the validStates part of Limits: only valid positions are "UP", "DOWN" and "IN TRANSIT".
}

bool LandingGearSensor::needsMaintenance() const {                             // If the current reading is not one of the valid states, maintenance is required.
    const std::string& position = std::get<std::string>(getCurrentReading());  // getCurrentReading() returns the variant, std::get<std::string> gets the text out of it.
    const auto& valid = getLimits().validStates;
    return std::find(valid.begin(), valid.end(), position) == valid.end();    // std::find searches the list and returns end() if not found.
}

std::string LandingGearSensor::interpretReading() const {                     // Landing gear-specific wording for the readout.
    const std::string& position = std::get<std::string>(getCurrentReading());
    if (needsMaintenance()) return "GEAR POSITION FAULT (" + position + ")";
    return "GEAR " + position;
}