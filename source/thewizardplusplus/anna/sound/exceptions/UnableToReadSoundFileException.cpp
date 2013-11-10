#include "UnableToReadSoundFileException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

UnableToReadSoundFileException::UnableToReadSoundFileException(void) :
	ReadingException("unable to read sound file")
{}
