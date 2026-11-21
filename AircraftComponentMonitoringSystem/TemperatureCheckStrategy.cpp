#include "TemperatureCheckStrategy.h"
#include "AircraftComponent.h"

std::string TemperatureCheckStrategy::performCheck(const AircraftComponent& component) const {
    double temperature = std::get<double>(component.getCurrentReading());  //asks the component for its current reading, and extracts the double from it.
    const Limits& limits = component.getLimits();                          // takes a read-only reference to the component's operating limits, so it can check if the reading is within range.
    if (temperature < limits.min) return "LOW TEMPERATURE";
    if (temperature > limits.max) return "HIGH TEMPERATURE";
    return "NORMAL TEMPERATURE";
}

bool TemperatureCheckStrategy::needsMaintenance(const AircraftComponent& component) const {
    double temperature = std::get<double>(component.getCurrentReading());
    const Limits& limits = component.getLimits();
    return temperature < limits.min || temperature > limits.max;    // needs maintenance if the temperature is outside the limits.
}