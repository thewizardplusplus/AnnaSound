#include "SoundException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

SoundException::SoundException(const std::string& message) :
	std::runtime_error("AnnaSound error: " + message + ".")
{}
