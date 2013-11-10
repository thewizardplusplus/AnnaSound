#ifndef SOUND_H
#define SOUND_H

namespace thewizardplusplus {
namespace anna {
namespace sound {

class SoundManager;
class Source;
class Buffer;

class Sound {
public:
	Sound(SoundManager* manager, Source* source, Buffer* buffer);
	~Sound(void);
	Source* getSource(void) const;
	Buffer* getBuffer(void) const;

private:
	SoundManager* manager;
	Source*       source;
	Buffer*       buffer;
};

}
}
}
#endif
