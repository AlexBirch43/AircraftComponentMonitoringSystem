#pragma once
#include "AircraftComponent.h"

// UML: PressureSensor: Inherits from AircraftComponent 
class PressureSensor : public AircraftComponent {
public:
    explicit PressureSensor(const std::string& id);  //stops accidental implicit conversions from a string.

    std::string interpretReading() const override;   //providing a specific implementation for pressure sensors.
};