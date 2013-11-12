#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "AudioDeviceAttribute.h"
#include "PCMDataManager.h"
#include <map>
#include <list>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class AudioDevice;
class Sound;

class SoundManager {
public:
	explicit SoundManager(AudioDeviceAttribute::Map context_attributes =
		AudioDeviceAttribute::Map());
	~SoundManager(void);
	AudioDevice* getAudioDevice(void) const;
	PCMDataManager& getDataManager(void);
	Sound* createSound(const std::string& file_path, const std::string& format =
		std::string());
	Sound* takeOutSound(Sound* sound);

private:
	typedef std::list<Sound*> SoundList;

	AudioDevice*   audio_device;
	PCMDataManager data_manager;
	SoundList      sounds;
};

}
}
}
#endif
