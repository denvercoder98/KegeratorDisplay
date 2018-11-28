#ifndef SRC_MAIN_ENTITIES_ENTITYEXCEPTION_H_
#define SRC_MAIN_ENTITIES_ENTITYEXCEPTION_H_

#include <stdexcept>

namespace KegeratorDisplay {

class EntityException : public std::runtime_error {
public:
	EntityException(const std::string& message) :
		std::runtime_error(message) {};
	virtual ~EntityException() throw() {};
};

}

#endif
