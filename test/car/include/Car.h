#pragma once

#include "DcMotor.h"

class Car
{
public:
    void controlSpeed();

private:
    DcMotor mMotor;
};
