#include "PCMData.h"

using namespace thewizardplusplus::anna::sound;

PCMData::PCMData(void) :
	valid(false),
	data(NULL),
	size(0),
	type(PCMDataType::MONO),
	bits(PCMDataBits::BIT_16),
	frequency(0)
{}

PCMData::PCMData(const void* data, int size, PCMDataType::Types type,
	PCMDataBits::Types bits, int frequency)
:
	valid(true),
	data(data),
	size(size),
	type(type),
	bits(bits),
	frequency(frequency)
{}

bool PCMData::isValid(void) const {
	return valid;
}

const void* PCMData::getData(void) const {
	return data;
}

int PCMData::getSize(void) const {
	return size;
}

PCMDataType::Types PCMData::getType(void) const {
	return type;
}

PCMDataBits::Types PCMData::getBits(void) const {
	return bits;
}

int PCMData::getFrequency(void) const {
	return frequency;
}

void PCMData::reset(void) {
	*this = PCMData();
}
