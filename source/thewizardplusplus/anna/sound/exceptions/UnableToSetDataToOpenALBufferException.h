#ifndef UNABLETOSETDATATOOPENALBUFFEREXCEPTION_H
#define UNABLETOSETDATATOOPENALBUFFEREXCEPTION_H

#include "SettingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class UnableToSetDataToOpenALBufferException : public SettingException {
public:
	UnableToSetDataToOpenALBufferException(void);
};

}
}
}
}
#endif
