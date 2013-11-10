#ifndef UNABLETOCREATEOPENALSOURCEEXCEPTION_H
#define UNABLETOCREATEOPENALSOURCEEXCEPTION_H

#include "CreationException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToCreateOpenALSourceException : public CreationException {
public:
	UnableToCreateOpenALSourceException(void);
};

}
}
}
}
#endif
