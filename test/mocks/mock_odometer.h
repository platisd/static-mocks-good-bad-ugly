#pragma once

#include "gmock/gmock.h"

class MockOdometer
{
public:
    MOCK_METHOD(int, getDistance, (), ());

    static MockOdometer& getInstance()
    {
        static MockOdometer instance;
        return instance;
    }
};
