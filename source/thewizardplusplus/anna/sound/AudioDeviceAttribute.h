#ifndef AUDIODEVICEATTRIBUTE_H
#define AUDIODEVICEATTRIBUTE_H

#include <map>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class AudioDeviceAttribute {
public:
	enum Types {
		FREQUENCY,
		REFRESH,
		SYNC,
		MONO_SOURCES,
		STEREO_SOURCES
	};

	typedef std::map<Types, int> Map;
};

}
}
}
#endif
