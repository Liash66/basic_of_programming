#pragma once
#include <fstream>
#include <iostream>
#include <time.h>

namespace utils
{
	enum class LogLevel
	{
		DEBUG, INFO, ERROR, WARNING
	};

	class Log
	{
	private:
		static std::ofstream m_out;
		static LogLevel m_loglevel;

	public:
		Log() {}

		static void SetLogPath(const std::string& path)
		{
			m_out.open(path);
		}

		static void WriteLog(const std::string& loglevel, const std::string& msg)
		{
			time_t t;
			time(&t);
			std::cerr << "[" << loglevel << "] " << msg << " " << ctime(&t) << std::endl;
			m_out << "[" << loglevel << "] " << msg << " " << ctime(&t) << std::endl;
		}

		static void Write(const LogLevel& loglevel, const std::string& msg)
		{
			if (loglevel == LogLevel::DEBUG)
			{
#ifdef _DEBUG
				WriteLog("DEBUG", msg);
#endif
			}
			else if (loglevel == LogLevel::INFO)
			{
				WriteLog("INFO", msg);
			}
			else if (loglevel == LogLevel::ERROR)
			{
				WriteLog("ERROR", msg);
			}
			else if (loglevel == LogLevel::WARNING)
			{
				WriteLog("WARNING", msg);
			}
		}

		~Log() {}
	};

	std::ofstream Log::m_out;
	LogLevel Log::m_loglevel;
}