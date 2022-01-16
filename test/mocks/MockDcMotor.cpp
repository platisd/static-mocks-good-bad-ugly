#include "MockDcMotor.h"
#include "DcMotor.h"

int DcMotor::getSpeed()
{
    return MockDcMotor::getInstance().getSpeed();
}

void DcMotor::stop()
{
    MockDcMotor::getInstance().stop();
}
