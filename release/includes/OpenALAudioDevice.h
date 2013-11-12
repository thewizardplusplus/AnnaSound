#ifndef OPENALAUDIODEVICE_H
#define OPENALAUDIODEVICE_H

#include "AudioDevice.h"
#include <AL/alc.h>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class OpenALAudioDevice : public AudioDevice {
public:
	explicit OpenALAudioDevice(AudioDeviceAttribute::Map context_attributes =
		AudioDeviceAttribute::Map());
	virtual ~OpenALAudioDevice(void);
	virtual float getDopplerFactor(void) const;
	virtual void setDopplerFactor(float value);
	virtual float getSpeedOfSound(void) const;
	virtual void setSpeedOfSound(float units_per_second);
	virtual DistanceModel::Types getDistanceModel(void) const;
	virtual void setDistanceModel(DistanceModel::Types model);
	virtual Source* createSource(void);
	virtual Source* takeOutSource(Source* source);
	virtual Buffer* createBuffer(void);
	virtual Buffer* takeOutBuffer(Buffer* buffer);
	virtual void join(Buffer* buffer, Source* source);

private:
	typedef std::map<Source*, unsigned int> SourceMap;
	typedef std::map<Buffer*, unsigned int> BufferMap;

	ALCdevice*  openal_device;
	ALCcontext* openal_context;
	SourceMap   sources;
	BufferMap   buffers;
};

}
}
}
#endif
