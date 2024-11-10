#include "logger.h"

#include <iostream>

const char* Logger::logFileName = "hilbert.log";

const char* Logger::logLevelStringsTerminal[5] = {"\033[32m[DEBUG]\033[0m",
												  "\033[36m[INFO]\033[0m ",
												  "\033[33m[WARN]\033[0m ",
												  "\033[35m[ERROR]",
												  "\033[31m[FATAL]"};

const char* Logger::logLevelStrings[5] = {
	"[DEBUG]", "[INFO] ", "[WARN] ", "[ERROR]", "[FATAL]"};

std::stringstream Logger::msgstream;

Logger::LogLevel Logger::lvl = Logger::LogLevel::INFO;

std::ofstream Logger::logFile;

void Logger::info(const std::string& message) {
	log(Logger::LogLevel::INFO, message);
}

void Logger::debug(const std::string& message) {
	log(Logger::LogLevel::DEBUG, message);
}

void Logger::warn(const std::string& message) {
	log(Logger::LogLevel::WARN, message);
}

void Logger::error(const std::string& message) {
	log(Logger::LogLevel::ERROR, message);
}

void Logger::fatal(const std::string& message) {
	log(Logger::LogLevel::FATAL, message);
}

void Logger::setLogLevel(const LogLevel lvl) {
	Logger::lvl = lvl;
}

void Logger::info() {
	info(msgstream.str());
	clear();
}

void Logger::debug() {
	debug(msgstream.str());
	clear();
}

void Logger::warn() {
	warn(msgstream.str());
	clear();
}

void Logger::error() {
	error(msgstream.str());
	clear();
}

void Logger::fatal() {
	fatal(msgstream.str());
	clear();
}

void Logger::open() {
	logFile.open(logFileName, std::ios::out | std::ios::app);
}

void Logger::open(std::string customLogFileName) {
	logFile.open(customLogFileName, std::ios::out | std::ios::app);
}

void Logger::close() {
	logFile.close();
}

void Logger::log(const LogLevel lvl, const std::string& message) {
	if (Logger::lvl <= lvl) {
		if (logFile.is_open()) {
			logFile << logLevelStrings[static_cast<int>(lvl)] << " " << message
					<< std::endl;
		}
		std::cout << logLevelStringsTerminal[static_cast<int>(lvl)] << " "
				  << message << "\033[0m" << std::endl;
	}
}

void Logger::clear() {
	msgstream.clear();
	msgstream.str("");
}
