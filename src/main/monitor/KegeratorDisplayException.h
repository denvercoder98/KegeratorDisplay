#ifndef SRC_MAIN_MONITOR_KEGERATORDISPLAYEXCEPTION_H_
#define SRC_MAIN_MONITOR_KEGERATORDISPLAYEXCEPTION_H_

#include <stdexcept>

namespace KegeratorDisplay {

class KegeratorDisplayException : public std::runtime_error {
public:
	KegeratorDisplayException(const std::string& message) :
		std::runtime_error(message) {};
	virtual ~KegeratorDisplayException() throw() {};
};

}

#endif
