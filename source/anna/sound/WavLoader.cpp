#include "WavLoader.h"
#include "../utils/ByteOrderTester.h"
#include <fstream>
#include <iostream>

using namespace anna::sound;
using namespace utils;

std::list<std::string> WavLoader::getSupportedFormats(void) const {
	std::list<std::string> formats;
	try {
		formats.push_back("WAV");
	} catch (std::bad_alloc&) {}
	return formats;
}

PCMData WavLoader::load(std::istream& source)
	throw(exceptions::ReadingException)
{
	source.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::
		ifstream::badbit);
	try {
		size_t mark1 = readDoubleWord(source);
		source.seekg(4, std::ios_base::cur);
		size_t mark2 = readDoubleWord(source);
		size_t mark3 = readDoubleWord(source);
		if ((mark1 != 0x52494646 && mark1 != 0x46464952) || (mark2 != 0x57415645
			&& mark2 != 0x45564157) || (mark3 != 0x666d7420 && mark3 !=
			0x20746d66))
		{
			throw exceptions::ReadingException("anna::sound: unable to load "
				"sound data - invalid WAV-marks.");
		}

		size_t size1 = readDoubleWord(source);
		size_t format = readWord(source);
		if (size1 != 16 || format != 1) {
			throw exceptions::ReadingException("anna::sound: unable to load "
				"sound data - invalid WAV-type (or not PCM, or with "
				"compression).");
		}

		size_t number_of_channels = readWord(source);
		if (number_of_channels != 1 && number_of_channels != 2) {
			throw exceptions::ReadingException("anna::sound: unable to load "
				"sound data - invalid number of channels.");
		}

		size_t sample_rate = readDoubleWord(source);
		source.seekg(4 + 2, std::istream::cur);
		size_t bits_per_sample = readWord(source);
		if (bits_per_sample != 8 && bits_per_sample != 16) {
			throw exceptions::ReadingException("anna::sound: unable to load "
				"sound data - invalid bits per sample.");
		}

		size_t mark4 = readDoubleWord(source);
		if (mark4 != 0x64617461 && mark4 != 0x61746164) {
			throw exceptions::ReadingException("anna::sound: unable to load "
				"sound data - invalid WAV-marks.");
		}
		size_t data_size = readDoubleWord(source);
		std::cout << data_size << std::endl;

		char* data = new char[data_size];
		source.read(data, data_size);

		return PCMData(data, data_size, number_of_channels == 1 ? PCMData::MONO
			: PCMData::STEREO, bits_per_sample == 8 ? PCMData::BIT_8 : PCMData::
			BIT_16, sample_rate);
	} catch (const std::ifstream::failure& exception) {
		(void)exception;
		throw exceptions::ReadingException("anna::sound: unable to load sound "
			"data - unable to read sound file.");
	} catch(const std::bad_alloc& exception) {
		(void)exception;
		throw exceptions::ReadingException("anna::sound: unable to load sound "
			"data - in process of loading sound file was requested too much "
			"memory.");
	}
}

void WavLoader::unload(const PCMData& data) {
	delete[] static_cast<const char*>(data.getData());
}

unsigned int WavLoader::readWord(std::istream& in) const {
	char buffer[WORD_SIZE] = {0};
	in.read(buffer, WORD_SIZE);

	ByteOrder::Types byte_order = ByteOrderTester::test();
	switch (byte_order) {
		case ByteOrder::LITTLE_ENDIAN:
			return buffer[0] | buffer[1] << 8;
		case ByteOrder::BIG_ENDIAN: {
			return buffer[1] << 8 | buffer[0];
		}
		default:
			return 0;
	}
}

unsigned long WavLoader::readDoubleWord(std::istream& in) const {
	char buffer[DOUBLE_WORD_SIZE] = {0};
	in.read(buffer, DOUBLE_WORD_SIZE);

	ByteOrder::Types byte_order = ByteOrderTester::test();
	switch (byte_order) {
		case ByteOrder::LITTLE_ENDIAN:
			return buffer[0] | buffer[1] << 8 | buffer[2] << 16 | buffer[3] <<
				24;
		case ByteOrder::BIG_ENDIAN: {
			return buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[
				0];
		}
		default:
			return 0;
	}
}
