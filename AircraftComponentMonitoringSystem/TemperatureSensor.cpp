#include "TemperatureSensor.h"
#include "TemperatureCheckStrategy.h"
#include <format>

TemperatureSensor::TemperatureSensor(const std::string& id)
    : AircraftComponent(id, Limits{ -20.0, 1000.0, {} },     // set operating limits for temperature sensor (-20 to 1000. Units in degrees C).
		std::make_unique<TemperatureCheckStrategy>()) {      // temperature specific strategy is created and passed to the base class constructor.
}

std::string TemperatureSensor::interpretReading() const {
	return std::format("Temperature: {:.1f} C", std::get<double>(getCurrentReading())); // describes the reading itself, the check result comes from the strategy.
}