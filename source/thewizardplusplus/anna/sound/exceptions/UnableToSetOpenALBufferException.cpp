#include "UnableToSetOpenALBufferException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

UnableToSetOpenALBufferException::UnableToSetOpenALBufferException(void) :
	SettingException("unable to set OpenAL buffer to OpenAL source")
{}
