#include "SoundManager.h"
#include "OpenALAudioDevice.h"
#include "WavLoader.h"
#include "Buffer.h"
#include "Sound.h"

using namespace thewizardplusplus::anna::sound;

SoundManager::SoundManager(AudioDeviceAttribute::Map context_attributes) :
	audio_device(NULL)
{
	audio_device = AudioDevice::create<OpenALAudioDevice>(context_attributes);
	data_manager.setLoader(new WavLoader());
}

SoundManager::~SoundManager(void) {
	std::list<Sound*>::iterator i = sounds.begin();
	for (; i != sounds.end(); ++i) {
		delete *i;
		*i = NULL;
	}

	delete audio_device;
	audio_device = NULL;
}

AudioDevice* SoundManager::getAudioDevice(void) const {
	return audio_device;
}

PCMDataManager& SoundManager::getDataManager(void) {
	return data_manager;
}

Sound* SoundManager::createSound(const std::string& file_path, const std::
	string& format)
{
	PCMData data = data_manager.load(file_path, format);

	Buffer* buffer = audio_device->createBuffer();
	buffer->setData(data);

	Source* source = audio_device->createSource();
	audio_device->join(buffer, source);

	Sound* sound = new Sound(this, source, buffer);
	sounds.push_back(sound);

	return sound;
}

Sound* SoundManager::takeOutSound(Sound* sound) {
	sounds.remove(sound);
	return sound;
}
