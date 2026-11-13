#pragma once
#include <string>
#include "Limits.h"
#include "ReadingValue.h"

//UML Class Diagram: Base class: <<abstract>> AircraftComponent

class AircraftComponent {
public:
	AircraftComponent(const std::string& id, const Limits& limits);  // Constructor: runs when component is createdsets the component ID and operating limits
	virtual ~AircraftComponent() = default;                          // Destructor: runs when component is destroyed

    // Shared behaviour - identical for every component type
    const std::string& getId() const;                   // UML: + getId()
    void updateReading(const ReadingValue& value);      // UML: + updateReading(value)
    void displayStatus() const;                         // UML: + displayStatus()
     
    // Specialised behaviour - each component type must provide its own
    virtual bool needsMaintenance() const = 0;          // UML: + needsMaintenance()
    virtual std::string interpretReading() const = 0;   // UML: + interpretReading()

    // Visible to subclasses but not to outside code, giving sensors read-only access to the private data.
protected:
    const ReadingValue& getCurrentReading() const;
    const Limits& getLimits() const;


private:
    std::string m_id;                                  // UML: - id : string
    ReadingValue m_currentReading;                     // UML: - currentReading : ReadingValue
    Limits m_operatingLimits;                          // UML: - operatingLimits : Limits
};