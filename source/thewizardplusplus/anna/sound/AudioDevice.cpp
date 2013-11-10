#include "AudioDevice.h"
#include "Listener.h"
#include <cstdlib>

using namespace thewizardplusplus::anna::sound;

AudioDevice::AudioDevice(void) :
	listener(NULL)
{}

AudioDevice::~AudioDevice(void) {
	delete listener;
	listener = NULL;
}

Listener* AudioDevice::getListener(void) {
	return listener;
}
