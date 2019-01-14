#ifndef SRC_MAIN_ENTITIES_INVALIDDATEEXCEPTION_H_
#define SRC_MAIN_ENTITIES_INVALIDDATEEXCEPTION_H_

#include "EntityException.h"

namespace KegeratorDisplay {

class InvalidDateException: public EntityException
{
public:
    InvalidDateException(const std::string& message) :
        EntityException(message) {};
    virtual ~InvalidDateException() throw() {};
};

}

#endif
