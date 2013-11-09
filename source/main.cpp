#include "anna/sound/SoundManager.h"
#include "anna/sound/Sound.h"
#include <iostream>

using namespace anna::sound;

int main(void) {
	try {
		SoundManager sound_manager;
		Sound* sound = sound_manager.createSound("test.wav");

		sound->getSource()->play();
		while (sound->getSource()->getState() == Source::PLAYING) {}
	} catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
