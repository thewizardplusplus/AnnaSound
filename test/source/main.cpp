#include <anna/sound/SoundManager.h>
#include <anna/sound/Sound.h>
#include <anna/sound/Source.h>
#include <anna/sound/Buffer.h>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

static const std::string DATA_PATH = "data/";
static const std::string WIND_FILENAME = DATA_PATH + "wind.wav";
static const std::string FIRE_FILENAME = DATA_PATH + "fire.wav";
static const float FIRE_ROTATION_RADIUS = 10;
static const float FIRE_ROTATION_SPEED = 2;

std::string GetBasePath(const std::string& app_path);
float GetCurrentTime(void);
void Log(const std::string& message);
Sound* LoadAndPlayWind(
	SoundManager& sound_manager,
	const std::string& base_path
);
Sound* LoadAndPlayFire(
	SoundManager& sound_manager,
	const std::string& base_path
);
void RotateFire(Sound* fire, float current_time);
bool IsRightTime(float time);
std::string ToString(float number, size_t minimal_width = 0);
void LogFirePosition(Sound* fire);

int main(int number_of_arguments, char* arguments[]) try {
	(void)number_of_arguments;

	SoundManager sound_manager;
	std::string base_path = GetBasePath(arguments[0]);
	Sound* wind = LoadAndPlayWind(sound_manager, base_path);
	Sound* fire = LoadAndPlayFire(sound_manager, base_path);

	bool output_flag = true;
	while (wind->getSource()->getState() == SourceState::PLAYING) {
		float current_time = GetCurrentTime();
		RotateFire(fire, current_time);

		if (output_flag && IsRightTime(current_time)) {
			LogFirePosition(fire);
			output_flag = false;
		} else if (!IsRightTime(current_time)) {
			output_flag = true;
		}
	}
} catch (const std::exception& exception) {
	std::cerr << exception.what() << std::endl;
}

std::string GetBasePath(const std::string& app_path) {
	std::string base_path;
	size_t separator_index = app_path.rfind('/');
	if (separator_index != std::string::npos) {
		base_path = app_path.substr(0, separator_index + 1);
	}

	return base_path;
}

Sound* LoadAndPlayWind(
	SoundManager& sound_manager,
	const std::string& base_path
) {
	Log("loading sound file \"" + WIND_FILENAME + "\"");
	Sound* wind = sound_manager.createSound(base_path + WIND_FILENAME);
	Log("loaded sound file \"" + WIND_FILENAME + "\"");

	wind->getSource()->play();
	Log("playing sound \"" + WIND_FILENAME + "\"");

	return wind;
}

void Log(const std::string& message) {
	float current_time_in_ms = 1000 * GetCurrentTime();
	std::cout
		<< ToString(current_time_in_ms, 5) << " ms\t"
		<< message << std::endl;
	std::cout << std::flush;
}

float GetCurrentTime(void) {
	return static_cast<float>(std::clock()) / CLOCKS_PER_SEC;
}

Sound* LoadAndPlayFire(
	SoundManager& sound_manager,
	const std::string& base_path
) {
	Log("loading sound file \"" + FIRE_FILENAME + "\"");
	Sound* fire = sound_manager.createSound(base_path + FIRE_FILENAME);
	Log("loaded sound file \"" + FIRE_FILENAME + "\"");

	fire->getSource()->setLooping(true);
	fire->getSource()->play();
	Log("playing sound \"" + FIRE_FILENAME + "\"");

	return fire;
}

void RotateFire(Sound* fire, float current_time) {
	float x =
		FIRE_ROTATION_RADIUS
		* std::cos(FIRE_ROTATION_SPEED * current_time);
	float y =
		FIRE_ROTATION_RADIUS
		* std::sin(FIRE_ROTATION_SPEED * current_time);
	Vector3D<float> new_position(x, y, 0);

	fire->getSource()->setPosition(new_position);
}

bool IsRightTime(float time) {
	return !(static_cast<int>(time * 10 + 0.5) % 5);
}

void LogFirePosition(Sound* fire) {
	Log(
		"sound \"" + FIRE_FILENAME + "\" source position is ("
			+ ToString(fire->getSource()->getPosition().x) + "; "
			+ ToString(fire->getSource()->getPosition().y)
		+ ")"
	);
}

std::string ToString(float number, size_t minimal_width) {
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	if (minimal_width > 0) {
		out << std::setw(minimal_width);
	}
	out << number;

	return out.str();
}
