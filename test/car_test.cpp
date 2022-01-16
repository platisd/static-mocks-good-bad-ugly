#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "Car.h"
#include "MockDcMotor.h"

using ::testing::Return;

TEST(CarTest, controlSpeedWhenSpeedTooHighWillStop)
{
    MockDcMotor& motor{MockDcMotor::getInstance()};
    Car car;
    EXPECT_CALL(motor, getSpeed()).WillOnce(Return(100));
    EXPECT_CALL(motor, stop());
    car.controlSpeed();
}

TEST(CarTest, controlSpeedWhenSpeedLowWillNotStop)
{
    MockDcMotor& motor{MockDcMotor::getInstance()};
    Car car;
    EXPECT_CALL(motor, getSpeed()).WillOnce(Return(49));
    EXPECT_CALL(motor, stop()).Times(0);
    car.controlSpeed();
}
