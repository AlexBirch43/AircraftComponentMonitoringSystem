#include "AlertService.h"
#include <utility>

bool AlertService::addChannel(std::unique_ptr<IAlertChannel> channel) { 
	if (!channel) return false;                 // rejects null channels, returns false if null.
	m_channels.push_back(std::move(channel));   // alert service takes ownership of the channel, so it can be used later to send alerts.
    return true;
}

void AlertService::sendAlert(const Alert& alert) const {  // each channel delivers the alert in its own way
    for (const auto& channel : m_channels) {
        channel->send(alert);
    }
}