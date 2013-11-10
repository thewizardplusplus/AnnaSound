#include "UnableToCreateOpenALContextException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

UnableToCreateOpenALContextException::UnableToCreateOpenALContextException(void)
:
	CreationException("unable to create OpenAL context")
{}
