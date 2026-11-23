#pragma once
#include "IAlertChannel.h"

// UML: MaintenancePanelAlert implements IAlertChannel.
class MaintenancePanelAlert : public IAlertChannel {
public:
    void send(const Alert& alert) const override;
};