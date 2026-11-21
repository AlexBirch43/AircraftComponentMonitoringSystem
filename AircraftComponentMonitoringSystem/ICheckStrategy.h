#pragma once 
#include <string>

class AircraftComponent;           //Forward declaration breaks circular dependency between component and strategy

// UML: <<interface>> ICheckStrategy
class ICheckStrategy {             // Declares the interface, "I" prefix is a convention meaning "interface" and matches the UML.
public:
    virtual ~ICheckStrategy() = default;
    virtual std::string performCheck(                     //// Pure virtual function: every strategy must supply its own version. Returns a status description like "NORMAL PRESSURE".
        const AircraftComponent& component) const = 0;    //// Takes the component to inspect as a read-only reference (const &): no copy, and the strategy can't change the component. The final "const" promises the strategy itself isn't changed either. "= 0" makes it pure virtual.
    virtual bool needsMaintenance(                        //// Second required function. Returns true if the component needs attention.
        const AircraftComponent& component) const = 0;
};