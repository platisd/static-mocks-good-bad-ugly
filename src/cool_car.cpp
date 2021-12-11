#include "cool_car.h"

#include <chrono>

void CoolCar::turn()
{
    if (gyroscope_.getAngle() > 0)
    {
        logger_.send("Turning left");
    }
    else
    {
        logger_.send("Turning right");
    }
}

void CoolCar::drive(int distance)
{
    logger_.send("Driving");
    while (true)
    {
        auto const left              = left_odometer_.getDistance();
        auto const right             = right_odometer_.getDistance();
        auto const traveled_distance = (left + right) / 2;
        if (traveled_distance > distance)
        {
            break;
        }
    }
}
