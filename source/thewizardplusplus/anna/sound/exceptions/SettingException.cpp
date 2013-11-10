#include "SettingException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

SettingException::SettingException(const std::string& message) :
	SoundException(message)
{}
