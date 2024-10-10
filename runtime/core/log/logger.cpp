// Logger.cpp
#include "logger.h"

namespace KAIBI 
{
	LogSystem::LogSystem()
	{
	}

	LogSystem::~LogSystem()
	{
	}

    std::string LogSystem::GetLogLevelString(LogLevel level) const
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
	
	std::string LogSystem::GetTime() const
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

	void LogSystem::Log(LogLevel level, std::string message, ...)
	{
		std::string logMessage = "[" + GetTime() + "]" + " [" + GetLogLevelString(level) + "] " + message + "\n";

		va_list args;
		va_start(args, message);
		vprintf(logMessage.c_str(), args);
		va_end(args);

	}
}
