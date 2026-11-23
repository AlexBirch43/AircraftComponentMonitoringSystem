#include "ComponentMonitor.h"

ComponentMonitor::ComponentMonitor(const ComponentRepository& repository,
    const AlertService& alertService)
    : m_repository(repository), m_alertService(alertService) {
}

// UML: + runChecks()
int ComponentMonitor::runChecks() const {                  // strategy decides what needs maintenance, alert service decides how its delivered.
    int alertsRaised = 0;                                  // counts alerts so callers (and tests) can see the outcome
    for (const auto& component : m_repository.getAll()) {  // check every stored component
        if (component->needsMaintenance()) {
            m_alertService.sendAlert(Alert{ component->getId(), component->performCheck() });
            ++alertsRaised;
        }
    }
    return alertsRaised;
}