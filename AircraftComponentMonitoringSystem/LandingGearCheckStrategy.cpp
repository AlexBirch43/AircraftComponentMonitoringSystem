#include "LandingGearCheckStrategy.h"
#include "AircraftComponent.h"
#include <algorithm>

std::string LandingGearCheckStrategy::performCheck(const AircraftComponent& component) const {  
	if (needsMaintenance(component)) return "GEAR POSITION FAULT";    // returns a fault message if the gear position is not valid.
    return "GEAR POSITION NORMAL";
}

bool LandingGearCheckStrategy::needsMaintenance(const AircraftComponent& component) const { 
	const std::string& position = std::get<std::string>(component.getCurrentReading());  // gets the reading and extracts as a string.
    const auto& valid = component.getLimits().validStates;
	return std::find(valid.begin(), valid.end(), position) == valid.end();  //std::find returns end() if the position is not found in the list of valid states.
}