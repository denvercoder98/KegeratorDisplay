#ifndef SRC_MAIN_ENTITIES_INVALIDINTERNATIONALBITTERNESSUNITSEXCEPTION_H_
#define SRC_MAIN_ENTITIES_INVALIDINTERNATIONALBITTERNESSUNITSEXCEPTION_H_

#include <entities/EntityException.h>

namespace KegeratorDisplay {

class InvalidInternationalBitternessUnitsException: public EntityException
{
public:
    InvalidInternationalBitternessUnitsException(const std::string& message) :
        EntityException(message) {};
    virtual ~InvalidInternationalBitternessUnitsException() throw() {};
};

}

#endif
