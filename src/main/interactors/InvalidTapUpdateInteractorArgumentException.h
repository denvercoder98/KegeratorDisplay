#ifndef SRC_MAIN_INTERACTORS_INVALIDTAPUPDATEINTERACTORARGUMENTEXCEPTION_H_
#define SRC_MAIN_INTERACTORS_INVALIDTAPUPDATEINTERACTORARGUMENTEXCEPTION_H_

#include <interactors/InteractorException.h>

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
