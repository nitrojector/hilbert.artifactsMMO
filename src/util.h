#pragma once

#include <map>
#include <string>

class Util {
  public:
	static std::map<std::string, std::string> getEnv();
};
