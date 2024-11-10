#include "util.h"

#include <fstream>

std::map<std::string, std::string> Util::getEnv() {
	std::map<std::string, std::string> env;
	std::ifstream file{".env"};
	if (!file) {
		return env;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line[0] == '#') {
			continue;
		}
		auto pos = line.find('=');
		if (pos != std::string::npos) {
			env[line.substr(0, pos)] = line.substr(pos + 1);
		}
	}

	return env;
}
