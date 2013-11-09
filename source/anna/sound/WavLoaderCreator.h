#ifndef WAVLOADERCREATOR_H
#define WAVLOADERCREATOR_H

#include "LoaderCreator.h"

namespace anna {
namespace sound {

class WavLoaderCreator : public LoaderCreator {
public:
	virtual Loader* createLoader(void);
};

}
}
#endif
