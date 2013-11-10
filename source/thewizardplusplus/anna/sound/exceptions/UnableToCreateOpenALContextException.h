#ifndef UNABLETOCREATEOPENALCONTEXTEXCEPTION_H
#define UNABLETOCREATEOPENALCONTEXTEXCEPTION_H

#include "CreationException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToCreateOpenALContextException : public CreationException {
public:
	UnableToCreateOpenALContextException(void);
};

}
}
}
}
#endif
