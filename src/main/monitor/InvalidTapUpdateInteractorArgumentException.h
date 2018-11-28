#ifndef SRC_MAIN_MONITOR_INVALIDTAPUPDATEINTERACTORARGUMENTEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDTAPUPDATEINTERACTORARGUMENTEXCEPTION_H_

#include "InteractorException.h"

namespace KegeratorDisplay {

class InvalidTapUpdateInteractorArgumentException: public InteractorException
{
public:
    InvalidTapUpdateInteractorArgumentException(const std::string& message) :
        InteractorException(message) {}
    virtual ~InvalidTapUpdateInteractorArgumentException() {}
};

}

#endif
