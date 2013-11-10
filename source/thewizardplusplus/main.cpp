#include "anna/sound/SoundManager.h"
#include "anna/sound/Sound.h"
#include "anna/sound/Source.h"
//#include <cmath>
#include <iostream>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

int main(void) {
	try {
		SoundManager sound_manager;
		Sound* sound = sound_manager.createSound("test3.wav");
		//sound->getSource()->setLooping(true);

		sound->getSource()->play();
		//float t = 0.0f;
		while (sound->getSource()->getState() == SourceState::PLAYING) {
			/*float x = 10 * std::cos(t);
			//float x = 0.0f;
			float y = 10 * std::sin(t);
			//float y = 0.0f;
			sound->getSource()->setPosition(Vector3D<float>(x, y, 0.0f));
			std::cout << "t = " << t << ", x = " << x << ", y = " << y << ";" <<
				std::endl;

			t += 0.000001f;*/
		}
	} catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
