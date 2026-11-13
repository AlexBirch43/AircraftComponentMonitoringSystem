#pragma once
#include "AircraftComponent.h"

// UML: TemperatureSensor: Inherits from AircraftComponent.
class TemperatureSensor : public AircraftComponent {
public:
    explicit TemperatureSensor(const std::string& id);    //stops accidental implicit conversions from a string.

    bool needsMaintenance() const override;          //replaces the pure virtual functions in AircraftComponent, 
    std::string interpretReading() const override;   //providing a specific implementation for pressure sensors.

};