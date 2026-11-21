#include "AircraftComponent.h"
#include <iostream>
#include <utility>

AircraftComponent::AircraftComponent(const std::string& id, const Limits& limits, //Constructor
    std::unique_ptr<ICheckStrategy> strategy)
    : m_id(id), m_operatingLimits(limits), m_strategy(std::move(strategy)) { //Initialiser list - sets private member variables as the object is created.
}

// UML: + getId()  -  Returns the component ID without allowing the caller to change it.
const std::string& AircraftComponent::getId() const { return m_id; }

const ReadingValue& AircraftComponent::getCurrentReading() const { return m_currentReading; }
const Limits& AircraftComponent::getLimits() const { return m_operatingLimits; }

// UML: + updateReading(value)  -  Updates the current reading of the component with a new value.
// The only public way to change reading.
void AircraftComponent::updateReading(const ReadingValue& value) {
    m_currentReading = value;
}

std::string AircraftComponent::performCheck() const {
	return m_strategy->performCheck(*this);    // Delegation: the component asks its strategy, passing itself as the subject.
}

bool AircraftComponent::needsMaintenance() const {
    return m_strategy->needsMaintenance(*this);
}

void AircraftComponent::displayStatus() const {
    std::cout << "Component " << m_id << " [" << interpretReading() << "]: "
        << performCheck()
        << (needsMaintenance() ? " - MAINTENANCE REQUIRED" : " - OK")
        << '\n';
}