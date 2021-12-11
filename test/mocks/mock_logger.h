
#pragma once

#include <string>

#include "gmock/gmock.h"

class MockLogger
{
public:
    MOCK_METHOD(void, send, (std::string), ());

    static MockLogger& getInstance()
    {
        static MockLogger instance;
        return instance;
    }
};
