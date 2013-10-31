#include "OGGLoaderCreator.h"
#include "OGGLoader.h"

using namespace anna::sound;

Loader* OGGLoaderCreator::createLoader(void) {
	Loader* loader = new OGGLoader();
	return loader;
}
