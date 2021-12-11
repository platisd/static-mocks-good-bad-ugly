#include "cool_car.h"

#include "gtest/gtest.h"

#include "mock_gyroscope.h"
#include "mock_logger.h"
#include "mock_odometer.h"

using ::testing::_;
using ::testing::Return;

class CoolCarTest : public ::testing::Test
{
public:
    CoolCar coolCar_{};
    MockGyroscope& gyroscope_{MockGyroscope::getInstance()};
    MockLogger& logger_{MockLogger::getInstance()};
    MockOdometer& odometer_{MockOdometer::getInstance()};
};

TEST_F(CoolCarTest, turn_WhenAnglePositive_WillTurnLeft)
{
    EXPECT_CALL(gyroscope_, getAngle()).WillOnce(Return(10));
    EXPECT_CALL(logger_, send("Turning left"));
    coolCar_.turn();
}

TEST_F(CoolCarTest, turn_WhenAngleNegative_WillTurnRight)
{
    EXPECT_CALL(gyroscope_, getAngle()).WillOnce(Return(-10));
    EXPECT_CALL(logger_, send("Turning right"));
    coolCar_.turn();
}

TEST_F(CoolCarTest, drive_WhenTraveledDistanceLargerThanTargetDistance_WillStop)
{
    auto const target_distance = 10;
    EXPECT_CALL(logger_, send(_));
    EXPECT_CALL(odometer_, getDistance())
        .WillRepeatedly(Return(target_distance * 2));
    coolCar_.drive(target_distance);
}

TEST_F(CoolCarTest,
       drive_WhenTraveledDistanceSmallerThanTargetDistance_WillContinue)
{
    auto const target_distance = 10;
    EXPECT_CALL(logger_, send(_));
    EXPECT_CALL(odometer_, getDistance())
        .WillOnce(Return(0))
        .WillOnce(Return(0))
        .WillOnce(Return(target_distance * 2))
        .WillOnce(Return(target_distance * 2));
    coolCar_.drive(target_distance);
}
