#ifndef SRC_MAIN_INTERACTORS_INVALIDADCREADINGVALUEEXCEPTION_H_
#define SRC_MAIN_INTERACTORS_INVALIDADCREADINGVALUEEXCEPTION_H_

#include <interactors/InteractorException.h>

namespace KegeratorDisplay {

class InvalidAdcReadingValueException: public InteractorException
{
public:
    InvalidAdcReadingValueException(const std::string& message) :
        InteractorException(message) {};
    virtual ~InvalidAdcReadingValueException() throw() {};
};

}

#endif
