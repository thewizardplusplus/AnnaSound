#ifndef PCMDATA_H
#define PCMDATA_H

#include "PCMDataType.h"
#include "PCMDataBits.h"
#include <cstdlib>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class PCMData {
public:
	PCMData(void);
	PCMData(const void* data, int size, PCMDataType::Types type, PCMDataBits::
		Types bits, int frequency);
	bool isValid(void) const;
	const void* getData(void) const;
	int getSize(void) const;
	PCMDataType::Types getType(void) const;
	PCMDataBits::Types getBits(void) const;
	int getFrequency(void) const;
	void reset(void);

private:
	bool               valid;
	const void*        data;
	int                size;
	PCMDataType::Types type;
	PCMDataBits::Types bits;
	int                frequency;
};

}
}
}
#endif
