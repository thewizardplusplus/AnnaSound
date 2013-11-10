#ifndef UNABLETOOPENSOUNDFILEEXCEPTION_H
#define UNABLETOOPENSOUNDFILEEXCEPTION_H

#include "ReadingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToOpenSoundFileException : public ReadingException {
public:
	UnableToOpenSoundFileException(const std::string& filename);
};

}
}
}
}
#endif
