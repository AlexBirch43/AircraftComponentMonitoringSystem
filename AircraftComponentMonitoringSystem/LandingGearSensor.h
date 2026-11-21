#pragma once
#include "AircraftComponent.h"

// UML: LandingGearSensor: Inherits from AircraftComponent.
class LandingGearSensor : public AircraftComponent {
public:
    explicit LandingGearSensor(const std::string& id);

    bool needsMaintenance() const override;
    std::string interpretReading() const override;
};