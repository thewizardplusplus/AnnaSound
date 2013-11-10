#include "Sound.h"
#include "SoundManager.h"
#include <cassert>

using namespace thewizardplusplus::anna::sound;

Sound::Sound(SoundManager* manager, Source* source, Buffer* buffer) :
	manager(manager),
	source(source),
	buffer(buffer)
{
	assert((manager != NULL && source != NULL && buffer != NULL) && "AnnaSound "
		"error: unable to create Sound with NULL SoundManager, NULL Source or "
		"NULL Buffer.");
}

Sound::~Sound(void) {}

Source* Sound::getSource(void) const {
	return source;
}

Buffer* Sound::getBuffer(void) const {
	return buffer;
}
