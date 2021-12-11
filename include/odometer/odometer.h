#pragma once

class Odometer
{
 public:
    int getDistance();

 private:
    int ticks_{0};
};
