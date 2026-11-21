#pragma once
#include "ICheckStrategy.h"

// UML: TemperatureCheckStrategy implements ICheckStrategy.
class TemperatureCheckStrategy : public ICheckStrategy {
public:
    std::string performCheck(const AircraftComponent& component) const override;
    bool needsMaintenance(const AircraftComponent& component) const override;
};