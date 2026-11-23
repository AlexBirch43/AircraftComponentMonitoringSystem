#pragma once
#include "Alert.h"

// UML: <<interface>> IAlertChannel
class IAlertChannel {
public:
    virtual ~IAlertChannel() = default;
    virtual void send(const Alert& alert) const = 0;
};