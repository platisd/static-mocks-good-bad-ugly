#include "logger.h"

#include <iostream>

void Logger::send(std::string message)
{
    std::cout << "[Logger]: " << message << std::endl;
}
