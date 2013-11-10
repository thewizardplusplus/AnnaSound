#include "OpenALListener.h"
#include <AL/al.h>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;

OpenALListener::OpenALListener(void) :
	gain(1.0f)
{
	alGetListener3f(AL_POSITION, &position.x, &position.z, &position.y);
	position.y = -position.y;

	float orientation[6] = {0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f};
	alGetListenerfv(AL_ORIENTATION, orientation);
	forward_direction.x = orientation[0];
	forward_direction.y = -orientation[2];
	forward_direction.z = orientation[1];
	up_direction.x = orientation[3];
	up_direction.y = -orientation[5];
	up_direction.z = orientation[4];

	alGetListener3f(AL_VELOCITY, &velocity.x, &velocity.z, &velocity.y);
	velocity.y = -velocity.y;

	alGetListenerf(AL_GAIN, &gain);
}

Vector3D<float> OpenALListener::getPosition(void) const {
	return position;
}

void OpenALListener::setPosition(const Vector3D<float>& position) {
	this->position = position;
	alListener3f(AL_POSITION, position.x, position.z, -position.y);
}

Vector3D<float> OpenALListener::getForwardDirection(void) const {
	return forward_direction;
}

void OpenALListener::setForwardDirection(const Vector3D<float>&
	forward_direction)
{
	this->forward_direction = forward_direction;
	setOrientation();
}

Vector3D<float> OpenALListener::getUpDirection(void) const {
	return up_direction;
}

void OpenALListener::setUpDirection(const Vector3D<float>& up_direction) {
	this->up_direction = up_direction;
	setOrientation();
}

Vector3D<float> OpenALListener::getVelocity(void) const {
	return velocity;
}

void OpenALListener::setVelocity(const Vector3D<float>& velocity) {
	this->velocity = velocity;
	alListener3f(AL_VELOCITY, velocity.x, velocity.z, -velocity.y);
}

float OpenALListener::getGain(void) const {
	return gain;
}

void OpenALListener::setGain(float gain) {
	this->gain = gain;
	alListenerf(AL_GAIN, gain);
}

void OpenALListener::setOrientation(void) {
	float orientation[6] = {forward_direction.x, forward_direction.z,
		-forward_direction.y, up_direction.x, up_direction.z, -up_direction.y};
	alListenerfv(AL_ORIENTATION, orientation);
}
