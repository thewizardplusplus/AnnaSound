#include <anna/sound/SoundManager.h>
#include <anna/sound/Sound.h>
#include <anna/sound/Source.h>
#include <anna/sound/Buffer.h>
#include <iostream>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

static const float RADIUS = 10.0f;
static const float SPEED = 3e-5;

std::string GetBasePath(const std::string& app_path) {
	std::string base_path;
	size_t separator_index = app_path.rfind('/');
	if (separator_index != std::string::npos) {
		base_path = app_path.substr(0, separator_index + 1);
	}

	return base_path;
}

int main(int number_of_arguments, char* arguments[]) try {
	(void)number_of_arguments;

	SoundManager sound_manager;

	std::string base_path = GetBasePath(arguments[0]);
	Sound* wind = sound_manager.createSound(base_path + "data/wind.wav");
	wind->getSource()->play();

	Sound* fire = sound_manager.createSound(base_path + "data/fire.wav");
	fire->getSource()->setLooping(true);
	fire->getSource()->play();

	float time = 0.0f;
	while (wind->getSource()->getState() == SourceState::PLAYING) {
		float x = RADIUS * std::cos(SPEED * time);
		float y = RADIUS * std::sin(SPEED * time);
		fire->getSource()->setPosition(Vector3D<float>(x, y, 0.0f));

		std::cout
			<< time << ":\t("
				<< fire->getSource()->getPosition().x << ";\t"
				<< fire->getSource()->getPosition().y
			<< ")" << std::endl
			<< std::flush;

		time++;
	}
} catch (const std::exception& exception) {
	std::cerr << exception.what() << std::endl;
}
