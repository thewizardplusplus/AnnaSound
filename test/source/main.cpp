#include <anna/sound/SoundManager.h>
#include <anna/sound/Sound.h>
#include <anna/sound/Source.h>
#include <anna/sound/Buffer.h>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

static const std::string WIND_SOUND_FILENAME = "data/wind.wav";
static const std::string FIRE_SOUND_FILENAME = "data/fire.wav";
static const float RADIUS = 10;
static const float SPEED = 2;

std::string GetBasePath(const std::string& app_path) {
	std::string base_path;
	size_t separator_index = app_path.rfind('/');
	if (separator_index != std::string::npos) {
		base_path = app_path.substr(0, separator_index + 1);
	}

	return base_path;
}

std::string ToString(float number) {
	std::ostringstream out;
	out << std::fixed << std::setprecision(2) << number;

	return out.str();
}

void Log(const std::string& message) {
	float time = 1000 * static_cast<float>(std::clock()) / CLOCKS_PER_SEC;
	std::cout << ToString(time) << " ms\t" << message << std::endl;
	std::cout << std::flush;
}

bool IsRightTime(float time) {
	return !(static_cast<int>(time * 10 + 0.5) % 5);
}

int main(int number_of_arguments, char* arguments[]) try {
	(void)number_of_arguments;

	SoundManager sound_manager;
	std::string base_path = GetBasePath(arguments[0]);
	Log("loading sound file \"" + WIND_SOUND_FILENAME + "\"");
	Sound* wind = sound_manager.createSound(base_path + WIND_SOUND_FILENAME);
	Log("loaded sound file \"" + WIND_SOUND_FILENAME + "\"");

	wind->getSource()->play();
	Log("playing sound \"" + WIND_SOUND_FILENAME + "\"");

	Log("loading sound file \"" + FIRE_SOUND_FILENAME + "\"");
	Sound* fire = sound_manager.createSound(base_path + "data/fire.wav");
	Log("loaded sound file \"" + FIRE_SOUND_FILENAME + "\"");

	fire->getSource()->setLooping(true);
	fire->getSource()->play();
	Log("playing sound \"" + FIRE_SOUND_FILENAME + "\"");

	bool output_flag = true;
	while (wind->getSource()->getState() == SourceState::PLAYING) {
		float time = static_cast<float>(std::clock()) / CLOCKS_PER_SEC;
		float x = RADIUS * std::cos(SPEED * time);
		float y = RADIUS * std::sin(SPEED * time);
		fire->getSource()->setPosition(Vector3D<float>(x, y, 0));

		if (output_flag && IsRightTime(time)) {
			Log(
				"sound \"" + FIRE_SOUND_FILENAME + "\" source position is ("
					+ ToString(fire->getSource()->getPosition().x) + "; "
					+ ToString(fire->getSource()->getPosition().y)
				+ ")"
			);

			output_flag = false;
		} else if (!IsRightTime(time)) {
			output_flag = true;
		}
	}
} catch (const std::exception& exception) {
	std::cerr << exception.what() << std::endl;
}
