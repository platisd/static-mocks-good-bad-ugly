
#include "mock_logger.h"

#include "logger.h"

void Logger::send(std::string message)
{
    MockLogger::getInstance().send(message);
}
