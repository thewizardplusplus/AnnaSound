#include "WavLoader.h"
#include "exceptions/UnableToReadSoundFileException.h"
#include "exceptions/RequestedTooMuchMemoryException.h"
#include "../../utils/ByteOrderTester.h"
#include <fstream>
#include <iostream>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::sound::exceptions;
using namespace thewizardplusplus::utils;

Loader::FormatList WavLoader::getSupportedFormats(void) const {
	FormatList formats;
	formats.push_back("WAV");

	return formats;
}

PCMData WavLoader::load(std::istream& source) {
	source.exceptions(std::ifstream::eofbit | std::ifstream::failbit | std::
		ifstream::badbit);
	try {
		size_t mark1 = read4Bytes(source);
		std::cout << "Mark1: \"" << std::string(reinterpret_cast<char*>(&mark1),
			4) << "\"." << std::endl;
		if (mark1 != 0x46464952) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"mark; expected \"RIFF\"");
		}

		source.seekg(4, std::ios_base::cur);
		size_t mark2 = read4Bytes(source);
		std::cout << "Mark2: \"" << std::string(reinterpret_cast<char*>(&mark2),
			4) << "\"." << std::endl;
		if (mark2 != 0x45564157) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"mark; expected \"WAVE\"");
		}

		size_t mark3 = read4Bytes(source);
		std::cout << "Mark3: \"" << std::string(reinterpret_cast<char*>(&mark3),
			4) << "\"." << std::endl;
		if (mark3 != 0x20746d66) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"mark; expected \"fmt \"");
		}

		size_t size_of_chunk1 = read4Bytes(source);
		std::cout << "Size of chunk 1: \"" << size_of_chunk1 << "\"." << std::
			endl;
		if (size_of_chunk1 != 16) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"type; not PCM, found extra format bytes");
		}

		size_t audio_format = read2Bytes(source);
		std::cout << "Audio format: \"" << audio_format << "\"." << std::endl;
		if (audio_format != 1) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"type; found compression");
		}

		size_t number_of_channels = read2Bytes(source);
		std::cout << "Number of channels: \"" << number_of_channels << "\"." <<
			std::endl;
		if (number_of_channels != 1 && number_of_channels != 2) {
			throw ReadingException("unable to load sound data; invalid number "
				"of channels");
		}
		PCMDataType::Types type = number_of_channels == 1 ? PCMDataType::MONO :
			PCMDataType::STEREO;

		size_t sample_rate = read4Bytes(source);
		std::cout << "Sample rate: \"" << sample_rate << "\"." << std::endl;

		source.seekg(4 + 2, std::ios_base::cur);
		size_t bits_per_sample = read2Bytes(source);
		std::cout << "Bits per sample: \"" << bits_per_sample << "\"." << std::
			endl;
		if (bits_per_sample != 8 && bits_per_sample != 16) {
			throw ReadingException("unable to load sound data; invalid bits per"
				" sample");
		}
		PCMDataBits::Types bits = bits_per_sample == 8 ? PCMDataBits::BIT_8 :
			PCMDataBits::BIT_16;

		size_t mark4 = read4Bytes(source);
		std::cout << "Mark4: \"" << std::string(reinterpret_cast<char*>(&mark4),
			4) << "\"." << std::endl;
		if (mark4 != 0x61746164) {
			throw ReadingException("unable to load sound data; invalid WAV-"
				"mark; expected \"data\"");
		}

		size_t size_of_chunk2 = read4Bytes(source);
		std::cout << "Size of chunk 2: \"" << size_of_chunk2 << "\"." << std::
			endl;

		/*size_t position = source.tellg();
		source.seekg(0, std::ios_base::end);
		std::cout << "Real size of data: \"" << (static_cast<size_t>(source.
			tellg()) - position) << "\"." << std::endl;
		source.seekg(position);*/

		char* data = new char[size_of_chunk2];
		source.exceptions(std::ifstream::goodbit);
		source.read(data, size_of_chunk2);

		return PCMData(data, size_of_chunk2, type, bits, sample_rate);
	} catch (const std::ifstream::failure& exception) {
		(void)exception;
		throw UnableToReadSoundFileException();
	} catch(const std::bad_alloc& exception) {
		(void)exception;
		throw RequestedTooMuchMemoryException();
	}
}

void WavLoader::free(PCMData& data) {
	delete[] static_cast<const char*>(data.getData());
	data.reset();
}

unsigned int WavLoader::read2Bytes(std::istream& in) const {
	char buffer[2] = {0};
	in.read(buffer, 2);

	ByteOrder::Types byte_order = ByteOrderTester::test();
	switch (byte_order) {
		case ByteOrder::LITTLE_ENDIAN:
			return static_cast<unsigned char>(buffer[0]) | static_cast<unsigned
				char>(buffer[1]) << 8;
		case ByteOrder::BIG_ENDIAN: {
			return static_cast<unsigned char>(buffer[1]) << 8 | static_cast<
				unsigned char>(buffer[0]);
		}
		default:
			return 0;
	}
}

unsigned long WavLoader::read4Bytes(std::istream& in) const {
	char buffer[4] = {0};
	in.read(buffer, 4);

	ByteOrder::Types byte_order = ByteOrderTester::test();
	switch (byte_order) {
		case ByteOrder::LITTLE_ENDIAN:
			return static_cast<unsigned char>(buffer[0]) | static_cast<unsigned
				char>(buffer[1]) << 8 | static_cast<unsigned char>(buffer[2]) <<
				16 | static_cast<unsigned char>(buffer[3]) << 24;
		case ByteOrder::BIG_ENDIAN: {
			return static_cast<unsigned char>(buffer[3]) << 24 | static_cast<
				unsigned char>(buffer[2]) << 16 | static_cast<unsigned char>(
				buffer[1]) << 8 | static_cast<unsigned char>(buffer[0]);
		}
		default:
			return 0;
	}
}
