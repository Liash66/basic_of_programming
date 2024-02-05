#include <iostream>
#include "Logger.h"

int main()
{
    utils::Log::SetLogPath("log.txt");

    utils::Log::Write(utils::LogLevel::DEBUG, "1");
    utils::Log::Write(utils::LogLevel::INFO, "2");
    utils::Log::Write(utils::LogLevel::ERROR, "3");
    utils::Log::Write(utils::LogLevel::WARNING, "4");

    return 0;
}