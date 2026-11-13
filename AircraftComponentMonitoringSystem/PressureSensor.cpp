#include "PressureSensor.h"


PressureSensor::PressureSensor(const std::string& id)
	: AircraftComponent(id, Limits{ 0.0, 100.0, {} }) {  //Set operating limits for pressure sensor (0 to 100 psi).
}

bool PressureSensor::needsMaintenance() const {          //If the current reading is outside operating limits, maintenance is required.
    double psi = std::get<double>(getCurrentReading());  //Extracts the number from ReadingValue variant.
    return psi < getLimits().min || psi > getLimits().max;
}

std::string PressureSensor::interpretReading() const {    // Pressure-specific wording for the readout.
    double psi = std::get<double>(getCurrentReading());
    if (psi < getLimits().min) return "LOW PRESSURE";
    if (psi > getLimits().max) return "HIGH PRESSURE";
    return "NORMAL PRESSURE";
}