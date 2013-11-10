#include "OpenALSource.h"
#include "OpenALAudioDevice.h"
#include <AL/al.h>
#include <cfloat>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

OpenALSource::OpenALSource(OpenALAudioDevice* audio_device, unsigned int
	openal_source)
:
	audio_device(audio_device),
	openal_source(openal_source),
	cone_inner_angle(360.0f),
	cone_outer_angle(360.0f),
	gain(1.0f),
	cone_outer_gain(0.0f),
	minimal_gain(0.0f),
	maximal_gain(1.0f),
	reference_distance(1.0f),
	rolloff_factor(1.0f),
	maximal_distance(FLT_MAX),
	pitch(1.0f),
	looping(false)
{
	alGetListener3f(AL_POSITION, &position.x, &position.z, &position.y);
	position.y = -position.y;
	alGetListener3f(AL_POSITION, &velocity.x, &velocity.z, &velocity.y);
	velocity.y = -velocity.y;
	alGetListener3f(AL_POSITION, &direction.x, &direction.z, &direction.y);
	direction.y = -direction.y;
	alGetSourcef(openal_source, AL_CONE_INNER_ANGLE, &cone_inner_angle);
	alGetSourcef(openal_source, AL_CONE_OUTER_ANGLE, &cone_outer_angle);

	alGetSourcef(openal_source, AL_GAIN, &gain);
	alGetSourcef(openal_source, AL_CONE_OUTER_GAIN, &cone_outer_gain);
	alGetSourcef(openal_source, AL_MIN_GAIN, &minimal_gain);
	alGetSourcef(openal_source, AL_MAX_GAIN, &maximal_gain);
	alGetSourcef(openal_source, AL_REFERENCE_DISTANCE, &reference_distance);
	alGetSourcef(openal_source, AL_ROLLOFF_FACTOR, &rolloff_factor);
	alGetSourcef(openal_source, AL_MAX_DISTANCE, &maximal_distance);

	alGetSourcef(openal_source, AL_PITCH, &pitch);
	int looping = 0;
	alGetSourcei(openal_source, AL_LOOPING, &looping);
	this->looping = looping;
}

OpenALSource::~OpenALSource(void) {
	alDeleteSources(1, &openal_source);
}

Vector3D<float> OpenALSource::getPosition(void) const {
	return position;
}

void OpenALSource::setPosition(const maths::Vector3D<float>& position) {
	this->position = position;
	alSource3f(openal_source, AL_POSITION, position.x, position.z, -position.y);
}

Vector3D<float> OpenALSource::getVelocity(void) const {
	return velocity;
}

void OpenALSource::setVelocity(const maths::Vector3D<float>& velocity) {
	this->velocity = velocity;
	alSource3f(openal_source, AL_VELOCITY, velocity.x, velocity.z, -velocity.y);
}

Vector3D<float> OpenALSource::getDirection(void) const {
	return direction;
}

void OpenALSource::setDirection(const maths::Vector3D<float>& direction) {
	this->direction = direction;
	alSource3f(openal_source, AL_DIRECTION, direction.x, direction.z,
		-direction.y);
}

float OpenALSource::getConeInnerAngle(void) const {
	return cone_inner_angle;
}

void OpenALSource::setConeInnerAngle(float angle_in_degrees) {
	cone_inner_angle = angle_in_degrees;
	alSourcef(openal_source, AL_CONE_INNER_ANGLE, angle_in_degrees);
}

float OpenALSource::getConeOuterAngle(void) const {
	return cone_outer_angle;
}

void OpenALSource::setConeOuterAngle(float angle_in_degrees) {
	cone_outer_angle = angle_in_degrees;
	alSourcef(openal_source, AL_CONE_OUTER_ANGLE, angle_in_degrees);
}

float OpenALSource::getGain(void) const {
	return gain;
}

void OpenALSource::setGain(float gain) {
	this->gain = gain;
	alSourcei(openal_source, AL_GAIN, gain);
}

float OpenALSource::getConeOuterGain(void) const {
	return cone_outer_gain;
}

void OpenALSource::setConeOuterGain(float gain) {
	cone_outer_gain = gain;
	alSourcef(openal_source, AL_CONE_OUTER_GAIN, gain);
}

float OpenALSource::getMinimalGain(void) const {
	return minimal_gain;
}

void OpenALSource::setMinimalGain(float minimal_gain) {
	this->minimal_gain = minimal_gain;
	alSourcef(openal_source, AL_MIN_GAIN, minimal_gain);
}

float OpenALSource::getMaximalGain(void) const {
	return maximal_gain;
}

void OpenALSource::setMaximalGain(float maximal_gain) {
	this->maximal_gain = maximal_gain;
	alSourcef(openal_source, AL_MAX_GAIN, maximal_gain);
}

float OpenALSource::getReferenceDistance(void) const {
	return reference_distance;
}

void OpenALSource::setReferenceDistance(float reference_distance) {
	this->reference_distance = reference_distance;
	alSourcef(openal_source, AL_REFERENCE_DISTANCE, reference_distance);
}

float OpenALSource::getRolloffFactor(void) const {
	return rolloff_factor;
}

void OpenALSource::setRolloffFactor(float rolloff_factor) {
	this->rolloff_factor = rolloff_factor;
	alSourcef(openal_source, AL_ROLLOFF_FACTOR, rolloff_factor);
}

float OpenALSource::getMaximalDistance(void) const {
	return maximal_distance;
}

void OpenALSource::setMaximalDistance(float maximal_distance) {
	this->maximal_distance = maximal_distance;
	alSourcef(openal_source, AL_MAX_DISTANCE, maximal_distance);
}

float OpenALSource::getPitch(void) const {
	return pitch;
}

void OpenALSource::setPitch(float pitch) {
	this->pitch = pitch;
	alSourcei(openal_source, AL_PITCH, pitch);
}

bool OpenALSource::getLooping(void) const {
	return looping;
}

void OpenALSource::setLooping(bool looping) {
	this->looping = looping;
	alSourcei(openal_source, AL_LOOPING, looping);
}

SourceState::Types OpenALSource::getState(void) const {
	int state = 0;
	alGetSourcei(openal_source, AL_SOURCE_STATE, &state);
	switch (state) {
		case AL_INITIAL:
			return SourceState::INITIAL;
		case AL_PLAYING:
			return SourceState::PLAYING;
		case AL_PAUSED:
			return SourceState::PAUSED;
		case AL_STOPPED:
			return SourceState::STOPPED;
		default:
			return SourceState::UNKNOWN;
	}
}

float OpenALSource::getOffset(SourceOffsetUnits::Types units) const {
	float offset = 0.0f;
	switch (units) {
		case SourceOffsetUnits::SECONDS:
			alGetSourcef(openal_source, AL_SEC_OFFSET, &offset);
			break;
		case SourceOffsetUnits::SAMPLES:
			alGetSourcef(openal_source, AL_SAMPLE_OFFSET, &offset);
			break;
		case SourceOffsetUnits::BYTES:
			alGetSourcef(openal_source, AL_BYTE_OFFSET, &offset);
			break;
	}

	return offset;
}

void OpenALSource::setOffset(float offset, SourceOffsetUnits::Types units) {
	switch (units) {
		case SourceOffsetUnits::SECONDS:
			alSourcef(openal_source, AL_SEC_OFFSET, offset);
			break;
		case SourceOffsetUnits::SAMPLES:
			alSourcef(openal_source, AL_SAMPLE_OFFSET, offset);
			break;
		case SourceOffsetUnits::BYTES:
			alSourcef(openal_source, AL_BYTE_OFFSET, offset);
			break;
	}
}

void OpenALSource::play(void) {
	alSourcePlay(openal_source);
}

void OpenALSource::pause(void) {
	alSourcePause(openal_source);
}

void OpenALSource::stop(void) {
	alSourceStop(openal_source);
}

void OpenALSource::rewind(void) {
	alSourceRewind(openal_source);
}
