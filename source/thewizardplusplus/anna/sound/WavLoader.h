#ifndef WAVLOADER_H
#define WAVLOADER_H

#include "Loader.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class WavLoader : public Loader {
public:
	virtual FormatList getSupportedFormats(void) const;
	virtual PCMData load(std::istream& source);
	virtual void free(PCMData& data);

private:
	unsigned int read2Bytes(std::istream& in) const;
	unsigned long read4Bytes(std::istream& in) const;
};

}
}
}
#endif
