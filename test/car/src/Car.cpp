#include "Car.h"

void Car::controlSpeed()
{
    if (mMotor.getSpeed() > 50)
    {
        mMotor.stop();
    }
}
