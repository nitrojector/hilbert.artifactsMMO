#pragma once

#include <fstream>
#include <sstream>
#include <string>

class Logger {
  public:
	enum class LogLevel { DEBUG, INFO, WARN, ERROR, FATAL };

	inline static std::ostream& stream() { return msgstream; }

	static void info(const std::string& message);
	static void debug(const std::string& message);
	static void warn(const std::string& message);
	static void error(const std::string& message);
	static void fatal(const std::string& message);

	static void info();
	static void debug();
	static void warn();
	static void error();
	static void fatal();

	static void setLogLevel(const LogLevel lvl);

	static void open();
	static void close();

  private:
	static const char* logFileName;

	static const char* logLevelStringsTerminal[5];
	static const char* logLevelStrings[5];

	static LogLevel lvl;

	static std::ofstream logFile;

	static std::stringstream msgstream;

	static void log(const LogLevel lvl, const std::string& message);

	static void clear();
};
