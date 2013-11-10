#ifndef UNABLETOSETOPENALBUFFEREXCEPTION_H
#define UNABLETOSETOPENALBUFFEREXCEPTION_H

#include "SettingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToSetOpenALBufferException : public SettingException {
public:
	UnableToSetOpenALBufferException(void);
};

}
}
}
}
#endif
