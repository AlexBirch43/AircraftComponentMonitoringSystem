#pragma once
#include "AlertService.h"
#include "ComponentRepository.h"

// UML: ComponentMonitor
class ComponentMonitor {  // coordinates checking - reads components from the repository and reports problems through alert service
public:
    ComponentMonitor(const ComponentRepository& repository, const AlertService& alertService);

    // UML: + runChecks(). 
    int runChecks() const; // raises one alert for every component that needs maintenance- returns the number of alerts raised (not in the UML, added to make testing easier).

private:
    // UML: - repository, - alertService.
    const ComponentRepository& m_repository;   // held by reference so monitor uses program's real instances, not copies.
    const AlertService& m_alertService;
};