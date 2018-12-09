#ifndef SRC_MAIN_INTERACTORS_INVALIDSCREENTOUCHEDINTERACTORARGUMENTEXCEPTION_H_
#define SRC_MAIN_INTERACTORS_INVALIDSCREENTOUCHEDINTERACTORARGUMENTEXCEPTION_H_

#include "interactors/InteractorException.h"

namespace KegeratorDisplay {

class InvalidScreenTouchedInteractorArgumentException : public InteractorException
{
public:
    InvalidScreenTouchedInteractorArgumentException(const std::string& message) :
        InteractorException(message) {}
    virtual ~InvalidScreenTouchedInteractorArgumentException() {}
};

}

#endif
