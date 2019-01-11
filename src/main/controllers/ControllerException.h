#ifndef SRC_MAIN_MONITOR_CONTROLLEREXCEPTION_H_
#define SRC_MAIN_MONITOR_CONTROLLEREXCEPTION_H_

#include <stdexcept>

namespace KegeratorDisplay {

class ControllerException : public std::runtime_error {
public:
    ControllerException(const std::string& message) :
		std::runtime_error(message) {};
	virtual ~ControllerException() throw() {};
};

}

#endif
