#ifndef DISTANCEMODEL_H
#define DISTANCEMODEL_H

namespace thewizardplusplus {
namespace anna {
namespace sound {

class DistanceModel {
public:
	enum Types {
		NONE,
		LINEAR_DISTANCE,
		LINEAR_DISTANCE_CLAMPED,
		INVERSE_DISTANCE,
		INVERSE_DISTANCE_CLAMPED,
		EXPONENT_DISTANCE,
		EXPONENT_DISTANCE_CLAMPED,
		UNKNOWN
	};
};

}
}
}
#endif
