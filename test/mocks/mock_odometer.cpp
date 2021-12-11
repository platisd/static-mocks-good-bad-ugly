
#include "mock_odometer.h"

#include "odometer.h"

int Odometer::getDistance()
{
    static_cast<void>(ticks_);
    return MockOdometer::getInstance().getDistance();
}
