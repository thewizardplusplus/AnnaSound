#include "OpenALAudioDeviceCreator.h"
#include "OpenALAudioDevice.h"

using namespace anna::sound;

AudioDevice* OpenALAudioDeviceCreator::createAudioDevice(
	std::map<AudioDevice::ATTRIBUTE, int> context_attributes)
	throw(exceptions::CreationException)
{
	AudioDevice* audio_device = new OpenALAudioDevice(context_attributes);
	return audio_device;
}
