#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include "AudioDeviceAttribute.h"
#include "DistanceModel.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class Source;
class Buffer;
class Listener;

class AudioDevice {
public:
	template<typename AudioDeviceType>
	static AudioDeviceType* create(AudioDeviceAttribute::Map
		context_attributes);

	AudioDevice(void);
	virtual ~AudioDevice(void);
	virtual float getDopplerFactor(void) const = 0;
	virtual void setDopplerFactor(float value) = 0;
	virtual float getSpeedOfSound(void) const = 0;
	virtual void setSpeedOfSound(float units_per_second) = 0;
	virtual DistanceModel::Types getDistanceModel(void) const = 0;
	virtual void setDistanceModel(DistanceModel::Types model) = 0;
	Listener* getListener(void);
	virtual Source* createSource(void) = 0;
	virtual Source* takeOutSource(Source* source) = 0;
	virtual Buffer* createBuffer(void) = 0;
	virtual Buffer* takeOutBuffer(Buffer* buffer) = 0;
	virtual void join(Buffer* buffer, Source* source) = 0;

protected:
	Listener* listener;
};

template<typename AudioDeviceType>
AudioDeviceType* AudioDevice::create(AudioDeviceAttribute::Map
	context_attributes)
{
	return new AudioDeviceType(context_attributes);
}

}
}
}
#endif
