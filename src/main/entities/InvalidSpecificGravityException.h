#ifndef SRC_MAIN_ENTITIES_INVALIDSPECIFICGRAVITYEXCEPTION_H_
#define SRC_MAIN_ENTITIES_INVALIDSPECIFICGRAVITYEXCEPTION_H_

#include <entities/EntityException.h>

namespace KegeratorDisplay {

class InvalidSpecificGravityException : public EntityException {
public:
    InvalidSpecificGravityException(const std::string& message) :
		EntityException(message) {};
	virtual ~InvalidSpecificGravityException() throw() {};
};

}

#endif
