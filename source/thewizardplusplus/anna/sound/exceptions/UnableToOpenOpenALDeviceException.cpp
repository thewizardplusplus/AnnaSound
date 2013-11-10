#include "UnableToOpenOpenALDeviceException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

UnableToOpenOpenALDeviceException::UnableToOpenOpenALDeviceException(void) :
	CreationException("unable to open OpenAL device")
{}
