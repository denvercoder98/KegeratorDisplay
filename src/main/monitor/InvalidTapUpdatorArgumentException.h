#ifndef SRC_MAIN_MONITOR_INVALIDTAPUPDATORARGUMENTEXCEPTION_H_
#define SRC_MAIN_MONITOR_INVALIDTAPUPDATORARGUMENTEXCEPTION_H_

#include <monitor/KegeratorDisplayException.h>

namespace KegeratorDisplay {

class InvalidTapUpdatorArgumentException: public KegeratorDisplayException
{
public:
    InvalidTapUpdatorArgumentException(const std::string& message) :
        KegeratorDisplayException(message) {}
    virtual ~InvalidTapUpdatorArgumentException() {}
};

}

#endif
