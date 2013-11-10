#ifndef READINGEXCEPTION_H
#define READINGEXCEPTION_H

#include "SoundException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class ReadingException : public SoundException {
public:
	ReadingException(const std::string& message);
	virtual ~ReadingException(void) throw();
	virtual const char* what(void) const throw();
	void setFilename(const std::string& filename);

private:
	std::string message;
	std::string filename;
};

}
}
}
}
#endif
