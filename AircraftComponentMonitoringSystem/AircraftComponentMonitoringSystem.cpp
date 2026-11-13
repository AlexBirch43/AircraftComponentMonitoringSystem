#include <iostream>
#include "PressureSensor.h"
#include "TemperatureSensor.h"

int main() {
    PressureSensor pressureSensor("Hydraulic Pump Sensor 1");               //object in camel-case to follow C++ naming conventions.
    TemperatureSensor temperatureSensor("Engine Temperature Sensor 1");

    pressureSensor.updateReading(50.0);
    pressureSensor.displayStatus();

    pressureSensor.updateReading(150.0);
    pressureSensor.displayStatus();

    temperatureSensor.updateReading(25.0);
    temperatureSensor.displayStatus();

    temperatureSensor.updateReading(-25.0);
    temperatureSensor.displayStatus();

    return 0;
}