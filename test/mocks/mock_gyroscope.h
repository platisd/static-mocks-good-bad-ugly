#pragma once

#include "gmock/gmock.h"

class MockGyroscope
{
public:
    MOCK_METHOD(int, getAngle, (), ());

    static MockGyroscope& getInstance()
    {
        static MockGyroscope instance;
        return instance;
    }
};
