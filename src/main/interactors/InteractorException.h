#ifndef SRC_MAIN_INTERACTORS_INTERACTOREXCEPTION_H_
#define SRC_MAIN_INTERACTORS_INTERACTOREXCEPTION_H_

#include <stdexcept>

namespace KegeratorDisplay {

class InteractorException : public std::runtime_error {
public:
    InteractorException(const std::string& message) :
		std::runtime_error(message) {};
	virtual ~InteractorException() throw() {};
};

}

#endif
