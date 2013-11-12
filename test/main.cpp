#include <SoundManager.h>
#include <Sound.h>
#include <Source.h>
#include <Buffer.h>
#include <iostream>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

static const float RADIUS = 2.0f;
static const float SPEED =  1e-3;

int main(void) {
	try {
		SoundManager sound_manager;

		Sound* wind = sound_manager.createSound("wind.wav");
		wind->getSource()->setLooping(true);
		wind->getSource()->play();

		Sound* fire = sound_manager.createSound("fire.wav");
		fire->getSource()->setLooping(true);
		fire->getSource()->play();

		float time = 0.0f;
		while (wind->getSource()->getState() == SourceState::PLAYING || fire->
			getSource()->getState() == SourceState::PLAYING)
		{
			float x = RADIUS * std::cos(SPEED * time);
			float y = RADIUS * std::sin(SPEED * time);
			fire->getSource()->setPosition(Vector3D<float>(x, y, 0.0f));
			std::cout << time << ": (" << x << "; " << y << ")" << std::endl <<
				std::flush;

			time++;
		}
	} catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
