#ifndef WAVLOADER_H
#define WAVLOADER_H

#include "Loader.h"

namespace anna {
namespace sound {

class WavLoader : public Loader {
public:
	virtual std::list<std::string> getSupportedFormats(void) const;
	virtual PCMData load(std::istream& source)
		throw(exceptions::ReadingException);
	virtual void unload(const PCMData& data);

private:
	static const size_t WORD_SIZE =        2;
	static const size_t DOUBLE_WORD_SIZE = 4;
	static const size_t LONG_SIZE =        4;

	unsigned int readWord(std::istream& in) const;
	unsigned long readDoubleWord(std::istream& in) const;
};

}
}
#endif
