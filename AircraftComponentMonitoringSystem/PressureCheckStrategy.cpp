#include "PressureCheckStrategy.h"
#include "AircraftComponent.h"

std::string PressureCheckStrategy::performCheck(const AircraftComponent& component) const {
	double pressure = std::get<double>(component.getCurrentReading());  //asks the component for its current reading, and extracts the double from it.
	const Limits& limits = component.getLimits();                       // takes a read-only reference to the component's operating limits, so it can check if the reading is within range.
    if (pressure < limits.min) return "LOW PRESSURE";
    if (pressure > limits.max) return "HIGH PRESSURE";
    return "NORMAL PRESSURE";
}

bool PressureCheckStrategy::needsMaintenance(const AircraftComponent& component) const {  
    double pressure = std::get<double>(component.getCurrentReading());
    const Limits& limits = component.getLimits();
    return pressure < limits.min || pressure > limits.max;  // needs maintenance if the pressure is outside the limits.
}