#ifndef SOUNDEXCEPTION_H
#define SOUNDEXCEPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class SoundException : public std::runtime_error {
public:
	SoundException(const std::string& message);
};

}
}
}
}
#endif
