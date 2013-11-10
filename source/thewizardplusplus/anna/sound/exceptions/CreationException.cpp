#include "CreationException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

CreationException::CreationException(const std::string& message) :
	SoundException(message)
{}
