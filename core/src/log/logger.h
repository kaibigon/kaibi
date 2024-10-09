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
        static void Init();

        void Log(LogLevel level, const std::string& message, ...);

		static std::shared_ptr<Logger> GetInstance() { return s_Instance; }

    private:
        static std::shared_ptr<Logger> s_Instance;

        std::string GetTime() const;
        std::string GetLogLevelString(LogLevel level) const;
    };

} 

#define LOG_INFO(...) KAIBI::Logger::GetInstance()->Log(KAIBI::LogLevel::Info, __VA_ARGS__)
#define LOG_WARN(...) KAIBI::Logger::GetInstance()->Log(KAIBI::LogLevel::Warn, __VA_ARGS__)
#define LOG_ERROR(...) KAIBI::Logger::GetInstance()->Log(KAIBI::LogLevel::Error, __VA_ARGS__)