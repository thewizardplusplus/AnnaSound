#include "OpenALBuffer.h"
#include "OpenALAudioDevice.h"
#include "exceptions/UnableToSetDataToOpenALBufferException.h"
#include <AL/al.h>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::sound::exceptions;

OpenALBuffer::OpenALBuffer(OpenALAudioDevice* audio_device, unsigned int
	openal_buffer)
:
	audio_device(audio_device),
	openal_buffer(openal_buffer),
	size(0),
	type(PCMDataType::MONO),
	bits(PCMDataBits::BIT_16),
	frequency(0)
{
	alGetBufferi(openal_buffer, AL_SIZE, &size);
	int channels = 1;
	alGetBufferi(openal_buffer, AL_CHANNELS, &channels);
	if (channels == 2) {
		type = PCMDataType::STEREO;
	}
	int bits = 16;
	alGetBufferi(openal_buffer, AL_BITS, &bits);
	if (bits == 8) {
		this->bits = PCMDataBits::BIT_8;
	}
	alGetBufferi(openal_buffer, AL_FREQUENCY, &frequency);
}

OpenALBuffer::~OpenALBuffer(void) {
	alDeleteBuffers(1, &openal_buffer);
}

int OpenALBuffer::getSize(void) const {
	return size;
}

PCMDataType::Types OpenALBuffer::getType(void) const {
	return type;
}

PCMDataBits::Types OpenALBuffer::getBits(void) const {
	return bits;
}

int OpenALBuffer::getFrequency(void) const {
	return frequency;
}

void OpenALBuffer::setData(const PCMData& data) {
	if (!data.isValid()) {
		return;
	}

	size =      data.getSize();
	type =      data.getType();
	bits =      data.getBits();
	frequency = data.getFrequency();

	int format = AL_FORMAT_MONO16;
	if (type == PCMDataType::MONO) {
		if (bits == PCMDataBits::BIT_8) {
			format = AL_FORMAT_MONO8;
		}
	} else {
		if (bits == PCMDataBits::BIT_8) {
			format = AL_FORMAT_STEREO8;
		} else {
			format = AL_FORMAT_STEREO16;
		}
	}

	alBufferData(openal_buffer, format, data.getData(), size, frequency);
	if (alGetError() != AL_NO_ERROR) {
		throw UnableToSetDataToOpenALBufferException();
	}
}
