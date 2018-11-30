#ifndef SRC_MAIN_CONTROLLER_INVALIDUSERINPUTCONTROLLERARGUMENTEXCEPTION_H_
#define SRC_MAIN_CONTROLLER_INVALIDUSERINPUTCONTROLLERARGUMENTEXCEPTION_H_

#include <controller/ControllerException.h>

namespace KegeratorDisplay {

class InvalidUserInputControllerArgumentException: public ControllerException
{
public:
    InvalidUserInputControllerArgumentException(const std::string& message) :
        ControllerException(message) {};
    virtual ~InvalidUserInputControllerArgumentException() throw() {};
};

}

#endif
