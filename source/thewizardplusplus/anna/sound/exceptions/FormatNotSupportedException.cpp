#include "FormatNotSupportedException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

FormatNotSupportedException::FormatNotSupportedException(const std::string&
	format)
:
	ReadingException(format + " format not supported")
{}
