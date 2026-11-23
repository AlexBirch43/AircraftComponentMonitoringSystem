#pragma once
#include <memory>
#include <vector>
#include "Alert.h"
#include "IAlertChannel.h"

// UML: AlertService
class AlertService {
public:

	bool addChannel(std::unique_ptr<IAlertChannel> channel);   // Adds a new alert channel and takes ownership. Returns false/adds nothing if channel is null

    void sendAlert(const Alert& alert) const;    // Sends the alert through every channel.

private:

    std::vector<std::unique_ptr<IAlertChannel>> m_channels;     // UML: - channels : List<IAlertChannel>
};