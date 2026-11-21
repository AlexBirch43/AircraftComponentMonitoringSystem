#include "PressureSensor.h"
#include "PressureCheckStrategy.h"
#include <format>

PressureSensor::PressureSensor(const std::string& id)
    : AircraftComponent(id, Limits{ 0.0, 100.0, {} },  //Set operating limits for pressure sensor (0 to 100. units are psi).
        std::make_unique<PressureCheckStrategy>()) {   // pressure specific strategy is created and passed to the base class constructor.
}

std::string PressureSensor::interpretReading() const {
    return std::format("Pressure: {:.1f}", std::get<double>(getCurrentReading())); // describes the reading itself, the check result comes from the strategy.
}