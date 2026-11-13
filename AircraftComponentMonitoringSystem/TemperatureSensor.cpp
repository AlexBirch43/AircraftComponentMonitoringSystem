#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(const std::string& id)
    : AircraftComponent(id, Limits{ -20.0, 1000.0, {} }) {      //Set operating limits for temperature sensor (-20 to 1000. Units in degrees C).
}

bool TemperatureSensor::needsMaintenance() const {            //If the current reading is outside operating limits, maintenance is required.
    double temperature = std::get<double>(getCurrentReading());      //Extracts the number from ReadingValue variant.
    return temperature < getLimits().min || temperature > getLimits().max;
}

std::string TemperatureSensor::interpretReading() const {     // Temperature-specific wording for the readout.
    double temperature = std::get<double>(getCurrentReading());
    if (temperature < getLimits().min) return "LOW TEMPERATURE";
    if (temperature > getLimits().max) return "HIGH TEMPERATURE";
    return "NORMAL TEMPERATURE";
}