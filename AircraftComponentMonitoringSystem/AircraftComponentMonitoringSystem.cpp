#include <iostream>
#include "PressureSensor.h"

int main() {
    PressureSensor hydraulic("PRS-001");

    hydraulic.updateReading(50.0);
    hydraulic.displayStatus();

    hydraulic.updateReading(150.0);
    hydraulic.displayStatus();

    return 0;
}