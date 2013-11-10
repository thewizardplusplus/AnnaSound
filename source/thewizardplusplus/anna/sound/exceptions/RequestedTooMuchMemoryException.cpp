#include "RequestedTooMuchMemoryException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

RequestedTooMuchMemoryException::RequestedTooMuchMemoryException(void) :
	ReadingException("in process of loading sound file was requested too much "
		"memory")
{}
