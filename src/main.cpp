#include "logger.h"
#include "util.h"

int main() {
	auto env = Util::getEnv();

	const std::string& TOKEN = env["ARTIFACTS_API_TOKEN"];

	Logger::open("hilbert.log");
	Logger::info("Hello, World!");
	Logger::debug("This is a debug message.");
	Logger::warn("This is a warning message.");
	Logger::error("This is an error message.");
	Logger::fatal("This is a fatal message.");
	Logger::stream() << "This is a message from the stream.";
	Logger::info();
	Logger::close();
	return 0;
}
