#ifndef SRC_MAIN_MONITOR_INVALIDSPECIFICGRAVITYEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDSPECIFICGRAVITYEXCEPTION_H_

#include "KegeratorDisplayException.h"

namespace KegeratorDisplay {

class InvalidSpecificGravityException : public KegeratorDisplayException {
public:
    InvalidSpecificGravityException(const std::string& message) :
		KegeratorDisplayException(message) {};
	virtual ~InvalidSpecificGravityException() throw() {};
};

}

#endif
