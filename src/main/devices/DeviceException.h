#ifndef SRC_MAIN_MONITOR_CONTROLLEREXCEPTION_H_
#define SRC_MAIN_MONITOR_CONTROLLEREXCEPTION_H_

#include <stdexcept>

namespace KegeratorDisplay {

class DeviceException : public std::runtime_error {
public:
    DeviceException(const std::string& message) :
		std::runtime_error(message) {};
	virtual ~DeviceException() throw() {};
};

}

#endif
