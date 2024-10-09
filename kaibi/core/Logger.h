#pragma once
#include "Core.h"
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace KAIBI 
{
    class KAIBI_API Logger {
    public:
        // Initializes the logger with console and file sinks
        static void Init();

        // Access the core logger
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

        // Access the client (sandbox) logger
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

} // namespace kaibi

// Core log macros
#define KAIBI_CORE_TRACE(...)   ::KAIBI::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define KAIBI_CORE_INFO(...)    ::KAIBI::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define KAIBI_CORE_WARN(...)    ::KAIBI::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define KAIBI_CORE_ERROR(...)   ::KAIBI::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define KAIBI_CORE_CRITICAL(...) ::KAIBI::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define KAIBI_CLIENT_TRACE(...) ::KAIBI::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define KAIBI_CLIENT_INFO(...)  ::KAIBI::Logger::GetClientLogger()->info(__VA_ARGS__)
#define KAIBI_CLIENT_WARN(...)  ::KAIBI::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define KAIBI_CLIENT_ERROR(...) ::KAIBI::Logger::GetClientLogger()->error(__VA_ARGS__)
#define KAIBI_CLIENT_CRITICAL(...) ::KAIBI::Logger::GetClientLogger()->critical(__VA_ARGS__)