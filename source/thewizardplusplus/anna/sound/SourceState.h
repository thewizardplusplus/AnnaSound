#ifndef SOURCESTATE_H
#define SOURCESTATE_H

namespace thewizardplusplus {
namespace anna {
namespace sound {

class SourceState {
public:
	enum Types {
		INITIAL,
		PLAYING,
		PAUSED,
		STOPPED,
		UNKNOWN
	};
};

}
}
}
#endif
