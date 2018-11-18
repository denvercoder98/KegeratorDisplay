#ifndef SRC_MAIN_MONITOR_INVALIDINTERNATIONALBITTERNESSUNITSEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDINTERNATIONALBITTERNESSUNITSEXCEPTION_H_

#include "KegeratorDisplayException.h"

namespace KegeratorDisplay {

class InvalidInternationalBitternessUnitsException: public KegeratorDisplayException
{
public:
    InvalidInternationalBitternessUnitsException(const std::string& message) :
        KegeratorDisplayException(message) {};
    virtual ~InvalidInternationalBitternessUnitsException() throw() {};
};

}

#endif
