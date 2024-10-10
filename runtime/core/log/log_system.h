#pragma once
#include "core/base/core.h"
#include "function/global/global_context.h"

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

    class KAPI LogSystem {
    public:
        LogSystem();
        ~LogSystem();

        // static void Init();

        // NOTE: For some reasons, the variadic arguments are not working if we pass message as reference (and only broken on Windows, no issues on Mac)
        // TODO: Find anohter work around here
        void Log(LogLevel level, std::string message, ...);

		// static std::shared_ptr<Logger> GetInstance() { return s_Instance; }

    private:
        // static std::shared_ptr<Logger> s_Instance;

        std::string GetTime() const;
        std::string GetLogLevelString(LogLevel level) const;
    };

} 

#define LOG_INFO(...) g_runtime_global_context.m_log_system->Log(KAIBI::LogLevel::Info, __VA_ARGS__)
#define LOG_WARN(...) g_runtime_global_context.m_log_system->Log(KAIBI::LogLevel::Warn, __VA_ARGS__)
#define LOG_ERROR(...) g_runtime_global_context.m_log_system->Log(KAIBI::LogLevel::Error, __VA_ARGS__)