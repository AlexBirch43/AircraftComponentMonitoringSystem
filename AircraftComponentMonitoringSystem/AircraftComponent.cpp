#include "AircraftComponent.h"
#include <iostream>

AircraftComponent::AircraftComponent(const std::string& id, const Limits& limits)  //Constructor
	: m_id(id), m_operatingLimits(limits) {       //Initialiser list - sets private member variables as the object is created.
}

// UML: + getId()  -  Returns the component ID without allowing the caller to change it.
const std::string& AircraftComponent::getId() const { return m_id; }

// UML: + updateReading(value)  -  Updates the current reading of the component with a new value.
// The only public way to change reading.
void AircraftComponent::updateReading(const ReadingValue& value) {
    m_currentReading = value;
}

// UML: + displayStatus()  -  Calls interpretReading() and needsMaintenance() to display the component's current status.
// This method is the same for all component types, New sensor types can be added without changing this.
void AircraftComponent::displayStatus() const {
    std::cout << "Component " << m_id << ": " << interpretReading()
        << (needsMaintenance() ? " - MAINTENANCE REQUIRED" : " - OK")
        << '\n';
}

//read-only access to private data.
const ReadingValue& AircraftComponent::getCurrentReading() const { return m_currentReading; }
const Limits& AircraftComponent::getLimits() const { return m_operatingLimits; }