#include <anna/sound/SoundManager.h>
#include <anna/sound/Sound.h>
#include <anna/sound/Source.h>
#include <anna/sound/Buffer.h>
#include <iostream>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

static const float RADIUS = 2.0f;
static const float SPEED = 1e-5;

std::string GetBasePath(const std::string& app_path) {
	std::string base_path;
	size_t separator_index = app_path.rfind('/');
	if (separator_index != std::string::npos) {
		base_path = app_path.substr(0, separator_index + 1);
	}

	return base_path;
}

Sound* LoadAndPlaySoundFile(
	SoundManager& sound_manager,
	const std::string& filename
) {
	Sound* sound = sound_manager.createSound(filename);
	sound->getSource()->setLooping(true);
	sound->getSource()->play();

	return sound;
}

void MoveSound(Sound* sound, float time) {
	float x = RADIUS * std::cos(SPEED * time);
	float y = RADIUS * std::sin(SPEED * time);
	Vector3D<float> new_position(x, y, 0.0f);

	sound->getSource()->setPosition(new_position);
}

void PrintSoundPosition(Sound* sound, float time) {
	std::cout
		<< time << ":\t("
			<< sound->getSource()->getPosition().x << ";\t"
			<< sound->getSource()->getPosition().y
		<< ")" << std::endl
		<< std::flush;
}

void ProcessError(const std::string& description) {
	std::cerr << description << std::endl;
}

int main(int number_of_arguments, char* arguments[]) try {
	(void)number_of_arguments;
	std::string base_path = GetBasePath(arguments[0]) + "data/";

	SoundManager sound_manager;
	LoadAndPlaySoundFile(sound_manager, base_path + "wind.wav");
	Sound* fire = LoadAndPlaySoundFile(sound_manager, base_path + "fire.wav");

	float time = 0.0f;
	while (true) {
		MoveSound(fire, time);
		PrintSoundPosition(fire, time);

		time++;
	}
} catch (const std::exception& exception) {
	ProcessError(exception.what());
}
