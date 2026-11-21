#pragma once
#include "ICheckStrategy.h"

// UML: PressureCheckStrategy implements ICheckStrategy
class PressureCheckStrategy : public ICheckStrategy {
public:
    std::string performCheck(const AircraftComponent& component) const override;
    bool needsMaintenance(const AircraftComponent& component) const override;
};