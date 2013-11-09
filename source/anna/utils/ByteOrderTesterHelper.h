#ifndef BYTEORDERTESTERHELPER_H
#define BYTEORDERTESTERHELPER_H

namespace utils {

union ByteOrderTesterHelper {
	typedef unsigned long Number;

	Number        number;
	unsigned char bytes[sizeof(Number)];
};

}
#endif
