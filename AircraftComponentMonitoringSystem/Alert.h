#pragma once
#include <string>

struct Alert {                 // Deviation from UML: gives the "alert" passed to sendAlert() and send() a concrete type.
    std::string componentId;
    std::string message;
};