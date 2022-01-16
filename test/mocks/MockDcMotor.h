#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MockDcMotor
{
public:
    MOCK_METHOD(int, getSpeed, (), ());
    MOCK_METHOD(void, stop, (), ());

    static MockDcMotor& getInstance()
    {
        static MockDcMotor instance;
        return instance;
    }

private:
    MockDcMotor() = default;
};
