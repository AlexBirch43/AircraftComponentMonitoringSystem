#pragma once
#include <memory>
#include <string>
#include <vector>
#include "AircraftComponent.h"

// UML: ComponentRepository. Stores and retrieves components only (single responsibility)
class ComponentRepository {
public:
    const std::vector<std::unique_ptr<AircraftComponent>>& getAll() const;  // read-only view of the stored components.

    AircraftComponent* findComponent(const std::string& id);                // returns the matching component or nullptr if not found.

    bool addComponent(std::unique_ptr<AircraftComponent> component);        // returns false if null or id already exists.
    
    bool removeComponent(const std::string& id);                            // returns false if no component has this id.

private:
    std::vector<std::unique_ptr<AircraftComponent>> m_components;           // UML: - components
};