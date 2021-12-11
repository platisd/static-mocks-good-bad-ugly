#include "mock_gyroscope.h"

#include "gyroscope.h"

int Gyroscope::getAngle()
{
    return MockGyroscope::getInstance().getAngle();
}
