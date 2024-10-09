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
