#ifndef OPENALSOURCE_H
#define OPENALSOURCE_H

#include "Source.h"

namespace thewizardplusplus {
namespace anna {
namespace sound {

class OpenALAudioDevice;

class OpenALSource : public Source {
public:
	OpenALSource(OpenALAudioDevice* audio_device, unsigned int openal_source);
	virtual ~OpenALSource(void);
	virtual maths::Vector3D<float> getPosition(void) const;
	virtual void setPosition(const maths::Vector3D<float>& position);
	virtual maths::Vector3D<float> getVelocity(void) const;
	virtual void setVelocity(const maths::Vector3D<float>& velocity);
	virtual maths::Vector3D<float> getDirection(void) const;
	virtual void setDirection(const maths::Vector3D<float>& direction);
	virtual float getConeInnerAngle(void) const;
	virtual void setConeInnerAngle(float angle_in_degrees);
	virtual float getConeOuterAngle(void) const;
	virtual void setConeOuterAngle(float angle_in_degrees);
	virtual float getGain(void) const;
	virtual void setGain(float gain);
	virtual float getConeOuterGain(void) const;
	virtual void setConeOuterGain(float gain);
	virtual float getMinimalGain(void) const;
	virtual void setMinimalGain(float minimal_gain);
	virtual float getMaximalGain(void) const;
	virtual void setMaximalGain(float maximal_gain);
	virtual float getReferenceDistance(void) const;
	virtual void setReferenceDistance(float reference_distance);
	virtual float getRolloffFactor(void) const;
	virtual void setRolloffFactor(float rolloff_factor);
	virtual float getMaximalDistance(void) const;
	virtual void setMaximalDistance(float maximal_distance);
	virtual float getPitch(void) const;
	virtual void setPitch(float pitch);
	virtual bool getLooping(void) const;
	virtual void setLooping(bool looping);
	virtual SourceState::Types getState(void) const;
	virtual float getOffset(SourceOffsetUnits::Types units) const;
	virtual void setOffset(float offset, SourceOffsetUnits::Types units);
	virtual void play(void);
	virtual void pause(void);
	virtual void stop(void);
	virtual void rewind(void);

private:
	OpenALAudioDevice*     audio_device;
	unsigned int           openal_source;
	maths::Vector3D<float> position;
	maths::Vector3D<float> velocity;
	maths::Vector3D<float> direction;
	float                  cone_inner_angle;
	float                  cone_outer_angle;
	float                  gain;
	float                  cone_outer_gain;
	float                  minimal_gain;
	float                  maximal_gain;
	float                  reference_distance;
	float                  rolloff_factor;
	float                  maximal_distance;
	float                  pitch;
	bool                   looping;
};

}
}
}
#endif
