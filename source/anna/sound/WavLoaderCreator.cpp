#include "WavLoaderCreator.h"
#include "WavLoader.h"

using namespace anna::sound;

Loader* WavLoaderCreator::createLoader(void) {
	Loader* loader = new WavLoader();
	return loader;
}
