#include "OpenALAudioDevice.h"
#include "exceptions/UnableToOpenOpenALDeviceException.h"
#include "exceptions/UnableToCreateOpenALContextException.h"
#include "OpenALListener.h"
#include "exceptions/UnableToCreateOpenALSourceException.h"
#include "OpenALSource.h"
#include "exceptions/UnableToCreateOpenALBufferException.h"
#include "OpenALBuffer.h"
#include "exceptions/UnableToSetOpenALBufferException.h"
#include <AL/al.h>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::sound::exceptions;

OpenALAudioDevice::OpenALAudioDevice(AudioDeviceAttribute::Map
	context_attributes)
:
	openal_device(NULL),
	openal_context(NULL)
{
	openal_device = alcOpenDevice(NULL);
	if (openal_device == NULL) {
		throw UnableToOpenOpenALDeviceException();
	}

	int* attributes = NULL;
	if (context_attributes.size()) {
		attributes = new int[context_attributes.size() * 2 + 1];

		AudioDeviceAttribute::Map::const_iterator i = context_attributes.
			begin();
		int j = 0;
		for (; i != context_attributes.end(); ++i) {
			switch (i->first) {
				case AudioDeviceAttribute::FREQUENCY:
					attributes[j] = ALC_FREQUENCY;
					break;
				case AudioDeviceAttribute::REFRESH:
					attributes[j] = ALC_REFRESH;
					break;
				case AudioDeviceAttribute::SYNC:
					attributes[j] = ALC_SYNC;
					break;
				case AudioDeviceAttribute::MONO_SOURCES:
					attributes[j] = ALC_MONO_SOURCES;
					break;
				case AudioDeviceAttribute::STEREO_SOURCES:
					attributes[j] = ALC_STEREO_SOURCES;
					break;
			}
			j++;

			attributes[j] = i->second;
			j++;
		}

		attributes[j] = 0;
	}

	openal_context = alcCreateContext(openal_device, attributes);
	delete[] attributes;
	attributes = NULL;
	if (openal_context == NULL) {
		throw UnableToCreateOpenALContextException();
	}
	alcMakeContextCurrent(openal_context);

	listener = new OpenALListener();
}

OpenALAudioDevice::~OpenALAudioDevice(void) {
	SourceMap::iterator i = sources.begin();
	for (; i != sources.end(); ++i) {
		delete i->first;
	}

	BufferMap::iterator j = buffers.begin();
	for (; j != buffers.end(); ++j) {
		delete j->first;
	}

	alcMakeContextCurrent(NULL);
	alcDestroyContext(openal_context);
	openal_context = NULL;
	alcCloseDevice(openal_device);
	openal_device = NULL;
}

float OpenALAudioDevice::getDopplerFactor(void) const {
	return alGetFloat(AL_DOPPLER_FACTOR);
}

void OpenALAudioDevice::setDopplerFactor(float value) {
	alDopplerFactor(value);
}

float OpenALAudioDevice::getSpeedOfSound(void) const {
	return alGetFloat(AL_SPEED_OF_SOUND);
}

void OpenALAudioDevice::setSpeedOfSound(float units_per_second) {
	alSpeedOfSound(units_per_second);
}

DistanceModel::Types OpenALAudioDevice::getDistanceModel(void) const {
	switch (alGetInteger(AL_DISTANCE_MODEL)) {
		case AL_NONE:
			return DistanceModel::NONE;
		case AL_LINEAR_DISTANCE:
			return DistanceModel::LINEAR_DISTANCE;
		case AL_LINEAR_DISTANCE_CLAMPED:
			return DistanceModel::LINEAR_DISTANCE_CLAMPED;
		case AL_INVERSE_DISTANCE:
			return DistanceModel::INVERSE_DISTANCE;
		case AL_INVERSE_DISTANCE_CLAMPED:
			return DistanceModel::INVERSE_DISTANCE_CLAMPED;
		case AL_EXPONENT_DISTANCE:
			return DistanceModel::EXPONENT_DISTANCE;
		case AL_EXPONENT_DISTANCE_CLAMPED:
			return DistanceModel::EXPONENT_DISTANCE_CLAMPED;
		default:
			return DistanceModel::UNKNOWN;
	}
}

void OpenALAudioDevice::setDistanceModel(DistanceModel::Types model) {
	switch (model) {
		case DistanceModel::NONE:
			alDistanceModel(AL_NONE);
			break;
		case DistanceModel::LINEAR_DISTANCE:
			alDistanceModel(AL_LINEAR_DISTANCE);
			break;
		case DistanceModel::LINEAR_DISTANCE_CLAMPED:
			alDistanceModel(AL_LINEAR_DISTANCE_CLAMPED);
			break;
		case DistanceModel::INVERSE_DISTANCE:
			alDistanceModel(AL_INVERSE_DISTANCE);
			break;
		case DistanceModel::INVERSE_DISTANCE_CLAMPED:
			alDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);
			break;
		case DistanceModel::EXPONENT_DISTANCE:
			alDistanceModel(AL_EXPONENT_DISTANCE);
			break;
		case DistanceModel::EXPONENT_DISTANCE_CLAMPED:
			alDistanceModel(AL_EXPONENT_DISTANCE_CLAMPED);
			break;
		case DistanceModel::UNKNOWN:
			alDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);
			break;
	}
}

Source* OpenALAudioDevice::createSource(void) {
	unsigned int openal_source = 0;
	alGenSources(1, &openal_source);
	if (alGetError() != AL_NO_ERROR) {
		throw UnableToCreateOpenALSourceException();
	}

	Source* source = new OpenALSource(this, openal_source);
	sources[source] = openal_source;

	return source;
}

Source* OpenALAudioDevice::takeOutSource(Source* source) {
	sources.erase(source);
	return source;
}

Buffer* OpenALAudioDevice::createBuffer(void) {
	unsigned int openal_buffer = 0;
	alGenBuffers(1, &openal_buffer);
	if (alGetError() != AL_NO_ERROR) {
		throw UnableToCreateOpenALBufferException();
	}

	Buffer* buffer = new OpenALBuffer(this, openal_buffer);
	buffers[buffer] = openal_buffer;

	return buffer;
}

Buffer* OpenALAudioDevice::takeOutBuffer(Buffer* buffer) {
	buffers.erase(buffer);
	return buffer;
}

void OpenALAudioDevice::join(Buffer* buffer, Source* source) {
	if (buffers.count(buffer) && sources.count(source)) {
		alSourcei(sources[source], AL_BUFFER, buffers[buffer]);
	} else if (buffer == NULL && sources.count(source)) {
		alSourcei(sources[source], AL_BUFFER, 0);
	} else {
		return;
	}
	if (alGetError() != AL_NO_ERROR) {
		throw UnableToSetOpenALBufferException();
	}
}
