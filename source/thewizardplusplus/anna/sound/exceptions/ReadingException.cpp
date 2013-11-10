#include "ReadingException.h"

using namespace thewizardplusplus::anna::sound::exceptions;

ReadingException::ReadingException(const std::string& message) :
	SoundException(message),
	message(message)
{}

ReadingException::~ReadingException(void) throw() {}

const char* ReadingException::what(void) const throw() {
	if (filename.empty()) {
		return SoundException::what();
	} else {
		return ("AnnaSound error: " + message + " (with file \"" + filename +
			"\").").c_str();
	}
}

void ReadingException::setFilename(const std::string& filename) {
	this->filename = filename;
}
