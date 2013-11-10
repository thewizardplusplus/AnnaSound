#ifndef SETTINGEXCEPTION_H
#define SETTINGEXCEPTION_H

#include "SoundException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class SettingException : public SoundException {
public:
	SettingException(const std::string& message);
};

}
}
}
}
#endif
