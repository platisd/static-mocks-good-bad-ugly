add_library(mocks mocks/mock_gyroscope.cpp mocks/mock_logger.cpp
                  mocks/mock_odometer.cpp)
target_include_directories(mocks PUBLIC mocks)
target_link_libraries(mocks gtest gmock gyroscope_api logger_api odometer_api)
target_compile_options(mocks PRIVATE -Wno-gnu-zero-variadic-macro-arguments)

add_executable(cool_car_test cool_car_test.cpp)
target_link_libraries(cool_car_test cool_car mocks)
configure_test(cool_car_test)
