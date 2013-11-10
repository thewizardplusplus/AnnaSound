#ifndef OPENALLISTENER_H
#define OPENALLISTENER_H

#include "Listener.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class OpenALListener : public Listener {
public:
	OpenALListener(void);
	virtual maths::Vector3D<float> getPosition(void) const;
	virtual void setPosition(const maths::Vector3D<float>& position);
	virtual maths::Vector3D<float> getForwardDirection(void) const;
	virtual void setForwardDirection(const maths::Vector3D<float>&
		forward_direction);
	virtual maths::Vector3D<float> getUpDirection(void) const;
	virtual void setUpDirection(const maths::Vector3D<float>& up_direction);
	virtual maths::Vector3D<float> getVelocity(void) const;
	virtual void setVelocity(const maths::Vector3D<float>& velocity);
	virtual float getGain(void) const;
	virtual void setGain(float gain);

private:
	maths::Vector3D<float> position;
	maths::Vector3D<float> forward_direction;
	maths::Vector3D<float> up_direction;
	maths::Vector3D<float> velocity;
	float                  gain;

	void setOrientation(void);
};

}
}
}
#endif
