#pragma once
#include "core/core.h"

// move to pch
#include <memory>
#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace KAIBI 
{
    enum class LogLevel
    {
        Info = 0,
        Warn,
        Error,
    };

    class KAPI Logger {
    public:

        void Log(LogLevel level, const std::string& message, ...);

        std::string GetTime() const;
        std::string GetLogLevelString(LogLevel level) const;
    private:
    };

} 