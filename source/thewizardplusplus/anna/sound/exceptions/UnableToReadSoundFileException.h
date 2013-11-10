#ifndef UNABLETOREADSOUNDFILEEXCEPTION_H
#define UNABLETOREADSOUNDFILEEXCEPTION_H

#include "ReadingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToReadSoundFileException : public ReadingException {
public:
	UnableToReadSoundFileException(void);
};

}
}
}
}
#endif
