// Logger.cpp
#include "logger.h"

namespace KAIBI 
{

	std::shared_ptr<Logger> Logger::s_Instance = nullptr;

	void Logger::Init()
	{
		if (!s_Instance)
		{
			s_Instance = std::make_shared<Logger>();
		}
	}

    std::string Logger::GetLogLevelString(LogLevel level) const
	{
		switch (level)
		{
		case LogLevel::Info:
			return "INFO";
		case LogLevel::Warn:
			return "WARN";
		case LogLevel::Error:
			return "ERROR";
		}
		return "INFO";
	}
	
	std::string Logger::GetTime() const
	{
		auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
#ifdef _WIN32
        localtime_s(&now_tm, &now_time);
#else
        localtime_r(&now_time, &now_tm);
#endif
        std::ostringstream stream;
        // stream << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
        stream << std::put_time(&now_tm, "%H:%M:%S");
        return stream.str();
	}

	void Logger::Log(LogLevel level, const std::string& message, ...)
	{
		std::string logMessage = "[" + GetTime() + "]" + " [" + GetLogLevelString(level) + "] " + message + "\n";
		va_list args;
		va_start(args, message);
		vprintf(logMessage.c_str(), args);
		va_end(args);
	}

    // std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    // std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

    // void Logger::Init()
	// {
	// 	spdlog::set_pattern("%^[%T] %n: %v%$");
	// 	s_CoreLogger = spdlog::stdout_color_mt("KAIBI");
	// 	s_CoreLogger->set_level(spdlog::level::trace);

	// 	s_ClientLogger = spdlog::stdout_color_mt("APP");
	// 	s_ClientLogger->set_level(spdlog::level::trace);
	// }
}
