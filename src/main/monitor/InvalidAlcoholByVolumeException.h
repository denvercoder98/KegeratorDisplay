#ifndef SRC_MAIN_MONITOR_INVALIDALCOHOLBYVOLUMEEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDALCOHOLBYVOLUMEEXCEPTION_H_

#include "KegeratorDisplayException.h"

namespace KegeratorDisplay {

class InvalidAlcoholByVolumeException : public KegeratorDisplayException {
public:
	InvalidAlcoholByVolumeException(const std::string& message) :
		KegeratorDisplayException(message) {};
	virtual ~InvalidAlcoholByVolumeException() throw() {};
};

}

#endif
