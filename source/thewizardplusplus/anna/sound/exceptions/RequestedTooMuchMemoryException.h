#ifndef REQUESTEDTOOMUCHMEMORYEXCEPTION_H
#define REQUESTEDTOOMUCHMEMORYEXCEPTION_H

#include "ReadingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class RequestedTooMuchMemoryException : public ReadingException {
public:
	RequestedTooMuchMemoryException(void);
};

}
}
}
}
#endif
