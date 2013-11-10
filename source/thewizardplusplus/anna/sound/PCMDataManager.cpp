#include "PCMDataManager.h"
#include "exceptions/FormatNotSupportedException.h"
#include "exceptions/UnableToOpenSoundFileException.h"
#include <fstream>
#include <locale>

using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::sound::exceptions;

PCMDataManager::~PCMDataManager(void) {
	DataMap::iterator i = data.begin();
	for (; i != data.end(); ++i) {
		Loader* loader = links[i->first];
		loader->free(i->second);
	}

	LoaderMap::const_iterator j = loaders.begin();
	for (; j != loaders.end(); ++j) {
		delete j->second;
	}
}

bool PCMDataManager::isLoader(const std::string& format) const {
	return loaders.count(toUpper(format));
}

void PCMDataManager::setLoader(Loader* loader) {
	if (loader != NULL) {
		Loader::FormatList formats = loader->getSupportedFormats();
		Loader::FormatList::const_iterator i = formats.begin();
		for (; i != formats.end(); ++i) {
			loaders[toUpper(*i)] = loader;
		}
	}
}

PCMData PCMDataManager::load(const std::string& file_path, const std::string&
	format)
{
	if (data.count(file_path)) {
		return data[file_path];
	}

	std::string file_format;
	if (format != "") {
		file_format = toUpper(format);
	} else {
		unsigned long position = file_path.rfind('.');
		if (position != std::string::npos) {
			file_format = toUpper(file_path.substr(position + 1, file_path.
				length()));
		}
	}
	if (!loaders.count(file_format)) {
		throw FormatNotSupportedException(file_format);
	}

	Loader* loader = loaders[file_format];

	std::ifstream file;
	file.open(file_path.c_str());
	if (!file.is_open()) {
		throw UnableToOpenSoundFileException(file_path);
	}

	PCMData pcm_data;
	try {
		pcm_data = loader->load(file);
	} catch (ReadingException& exception) {
		exception.setFilename(file_path);
		throw;
	}
	data[file_path] = pcm_data;
	links[file_path] = loader;
	file.close();

	return pcm_data;
}

std::string PCMDataManager::toUpper(const std::string& string) const {
	std::string result = string;
	std::locale locale;
	for (unsigned long i = 0; i < result.length(); i++) {
		result[i] = std::toupper(result[i], locale);
	}

	return result;
}
