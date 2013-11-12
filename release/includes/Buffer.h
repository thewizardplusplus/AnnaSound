#ifndef BUFFER_H
#define BUFFER_H

#include "PCMData.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class Buffer {
public:
	virtual ~Buffer(void);
	virtual int getSize(void) const = 0;
	virtual PCMDataType::Types getType(void) const = 0;
	virtual PCMDataBits::Types getBits(void) const = 0;
	virtual int getFrequency(void) const = 0;
	virtual void setData(const PCMData& data) = 0;
};

}
}
}
#endif
