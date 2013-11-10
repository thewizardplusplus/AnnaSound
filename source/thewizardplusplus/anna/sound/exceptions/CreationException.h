#ifndef CREATIONEXCEPTION_H
#define CREATIONEXCEPTION_H

#include "SoundException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class CreationException : public SoundException {
protected:
	CreationException(const std::string& message);
};

}
}
}
}
#endif
