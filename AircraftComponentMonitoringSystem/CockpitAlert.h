#pragma once
#include "IAlertChannel.h"

// UML: CockpitAlert implements IAlertChannel.
class CockpitAlert : public IAlertChannel {
public:
    void send(const Alert& alert) const override;
};