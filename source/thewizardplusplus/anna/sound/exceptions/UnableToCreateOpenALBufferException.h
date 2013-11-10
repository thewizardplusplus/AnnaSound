#ifndef UNABLETOCREATEOPENALBUFFEREXCEPTION_H
#define UNABLETOCREATEOPENALBUFFEREXCEPTION_H

#include "CreationException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToCreateOpenALBufferException : public CreationException {
public:
	UnableToCreateOpenALBufferException(void);
};

}
}
}
}
#endif
