add_executable(cool_car_test cool_car_test.cpp)
target_include_directories(cool_car_test PUBLIC mocks)
target_link_libraries(cool_car_test cool_car)
configure_test(cool_car_test)

add_library(dc_motor_interface INTERFACE)
target_include_directories(dc_motor_interface INTERFACE motor/include)

add_library(dc_motor motor/src/DcMotor.cpp)
target_link_libraries(dc_motor PUBLIC dc_motor_interface)

add_library(car car/src/Car.cpp)
target_include_directories(car PUBLIC car/include)
target_link_libraries(car PUBLIC dc_motor_interface)

add_library(mock_dc_motor mocks/MockDcMotor.cpp)
target_include_directories(mock_dc_motor PUBLIC mocks)
target_link_libraries(mock_dc_motor PUBLIC gtest gmock dc_motor_interface)
target_compile_options(mock_dc_motor
                       PRIVATE -Wno-gnu-zero-variadic-macro-arguments)

add_executable(car_test car_test.cpp)
target_link_libraries(car_test car mock_dc_motor)
configure_test(car_test)
