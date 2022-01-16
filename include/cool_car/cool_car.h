#pragma once

// cool_car/cool_car.h
#include "gyroscope.h"
#include "logger.h"
#include "odometer.h"

class CoolCar
{
public:
    void drive(int distance);
    void turn();

private:
    Gyroscope gyroscope_{};
    Odometer left_odometer_{};
    Odometer right_odometer_{};
    Logger logger_{};
};
