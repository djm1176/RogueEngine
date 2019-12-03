#include <iostream>
#include <iomanip>

#include "Logger.h"
#include "Flags.h"



void Debug::Log(const std::string& message) {
	std::cout << message << std::endl;
}

void Debug::LogWarning(const std::string& message) {
	std::cout << "WARNING:\t" << message << std::endl;
}

void Debug::LogError(const std::string& message) {
	std::cerr << "ERROR:\t" << message << std::endl;
}