#ifndef OPENALBUFFER_H
#define OPENALBUFFER_H

#include "Buffer.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class OpenALAudioDevice;

class OpenALBuffer : public Buffer {
public:
	OpenALBuffer(OpenALAudioDevice* audio_device, unsigned int openal_buffer);
	virtual ~OpenALBuffer(void);
	virtual int getSize(void) const;
	virtual PCMDataType::Types getType(void) const;
	virtual PCMDataBits::Types getBits(void) const;
	virtual int getFrequency(void) const;
	virtual void setData(const PCMData& data);

private:
	OpenALAudioDevice* audio_device;
	unsigned int       openal_buffer;
	int                size;
	PCMDataType::Types type;
	PCMDataBits::Types bits;
	int                frequency;
};

}
}
}
#endif
