cmake_minimum_required(VERSION 3.13)
project(static-mocks-the-good-the-bad-and-the-ugly)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(
  -Wcast-align
  -Wpedantic
  -Wcast-qual
  -Wconversion
  -Wctor-dtor-privacy
  -Wnon-virtual-dtor
  -Wmissing-include-dirs
  -Wdisabled-optimization
  -Winit-self
  -Wnon-virtual-dtor
  -Wold-style-cast
  -Woverloaded-virtual
  -Wparentheses
  -Wredundant-decls
  -Wshadow
  -Wsign-promo
  -Wstrict-aliasing
  -Wall
  -Wextra
  -Werror)

add_subdirectory(external)
enable_testing()

# Gyroscope #####
add_library(gyroscope_api INTERFACE)
target_include_directories(gyroscope_api INTERFACE include/gyroscope)

add_library(gyroscope src/gyroscope.cpp)
target_link_libraries(gyroscope PUBLIC gyroscope_api)

# Logger #####
add_library(logger_api INTERFACE)
target_include_directories(logger_api INTERFACE include/logger)

add_library(logger src/logger.cpp)
target_link_libraries(logger PUBLIC logger_api)

# Odometer #####
add_library(odometer_api INTERFACE)
target_include_directories(odometer_api INTERFACE include/odometer)

add_library(odometer src/odometer.cpp)
target_link_libraries(odometer PUBLIC odometer_api)

# Cool car #####
add_library(cool_car src/cool_car.cpp)
target_include_directories(cool_car PUBLIC include/cool_car)
target_link_libraries(cool_car PUBLIC gyroscope_api logger_api odometer_api)

add_executable(cool_car_main src/cool_car_main.cpp)
target_link_libraries(cool_car_main PUBLIC cool_car gyroscope logger odometer)

add_subdirectory(test)
