#ifndef LOADER_H
#define LOADER_H

#include "PCMData.h"
#include <list>
#include <istream>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class Loader {
public:
	typedef std::list<std::string> FormatList;

	virtual ~Loader(void);
	virtual FormatList getSupportedFormats(void) const = 0;
	virtual PCMData load(std::istream& source) = 0;
	virtual void free(PCMData& data) = 0;
};

}
}
}
#endif
