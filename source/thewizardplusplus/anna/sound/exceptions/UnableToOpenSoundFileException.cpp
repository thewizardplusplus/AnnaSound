#include "UnableToOpenSoundFileException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

UnableToOpenSoundFileException::UnableToOpenSoundFileException(const std::
	string& filename)
:
	ReadingException("unable to open sound file \"" + filename + "\"")
{}
