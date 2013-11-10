#ifndef PCMDATAMANAGER_H
#define PCMDATAMANAGER_H

#include "Loader.h"
#include <map>

namespace thewizardplusplus {
namespace anna {
namespace sound {

class PCMDataManager {
public:
	~PCMDataManager(void);
	bool isLoader(const std::string& format) const;
	void setLoader(Loader* loader);
	PCMData load(const std::string& file_path, const std::string& format = std::
		string());

private:
	typedef std::map<std::string, PCMData> DataMap;
	typedef std::map<std::string, Loader*> LoaderMap;

	DataMap   data;
	LoaderMap loaders;
	LoaderMap links;

	std::string toUpper(const std::string& string) const;
};

}
}
}
#endif
