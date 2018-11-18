#ifndef SRC_MAIN_MONITOR_INVALIDDATEEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDDATEEXCEPTION_H_

#include "KegeratorDisplayException.h"

namespace KegeratorDisplay {

class InvalidDateException: public KegeratorDisplayException
{
public:
    InvalidDateException(const std::string& message) :
        KegeratorDisplayException(message) {};
    virtual ~InvalidDateException() throw() {};
};

}

#endif
