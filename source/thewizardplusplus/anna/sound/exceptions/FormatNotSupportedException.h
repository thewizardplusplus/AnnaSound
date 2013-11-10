#ifndef FORMATNOTSUPPORTEDEXCEPTION_H
#define FORMATNOTSUPPORTEDEXCEPTION_H

#include "ReadingException.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {
namespace exceptions {

class FormatNotSupportedException : public ReadingException {
public:
	FormatNotSupportedException(const std::string& format);
};

}
}
}
}
#endif
