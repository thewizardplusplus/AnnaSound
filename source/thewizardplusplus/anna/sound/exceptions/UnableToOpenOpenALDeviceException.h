#ifndef UNABLETOOPENOPENALDEVICEEXCEPTION_H
#define UNABLETOOPENOPENALDEVICEEXCEPTION_H

#include "CreationException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToOpenOpenALDeviceException : public CreationException {
public:
	UnableToOpenOpenALDeviceException(void);
};

}
}
}
}
#endif
