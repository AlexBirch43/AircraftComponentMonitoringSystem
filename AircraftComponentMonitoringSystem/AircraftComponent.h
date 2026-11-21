#pragma once
#include <memory>
#include <string>
#include "ICheckStrategy.h"
#include "Limits.h"
#include "ReadingValue.h"

//UML Class Diagram: Base class: <<abstract>> AircraftComponent

class AircraftComponent {
public:
    
    AircraftComponent(const std::string& id, const Limits& limits,   // Constructor: runs when component is created, sets the component ID and operating limits
        std::unique_ptr<ICheckStrategy> strategy);                   // Takes ownership of the strategy supplied by the specific sensor type.
	virtual ~AircraftComponent() = default;                          // Destructor: runs when component is destroyed

    // Shared behaviour - identical for every component type
    const std::string& getId() const;                   // UML: + getId()

	const ReadingValue& getCurrentReading() const;    // moved into public so that the strategy can access.
    const Limits& getLimits() const;

    void updateReading(const ReadingValue& value);      // UML: + updateReading(value)

    std::string performCheck() const;                   // Strategy pattern: delegates to the strategy rather than hold the logic.
    bool needsMaintenance() const;

    void displayStatus() const;                         // UML: + displayStatus()
     
    // Specialised behaviour - each component type must provide its own
    virtual std::string interpretReading() const = 0;   // UML: + interpretReading()

private:
    std::string m_id;                                  // UML: - id : string
    ReadingValue m_currentReading;                     // UML: - currentReading : ReadingValue
    Limits m_operatingLimits;                          // UML: - operatingLimits : Limits
    std::unique_ptr<ICheckStrategy> m_strategy;        // UML: - strategy : ICheckStrategy
};