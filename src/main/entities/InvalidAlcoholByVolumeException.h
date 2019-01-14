#ifndef SRC_MAIN_ENTITIES_INVALIDALCOHOLBYVOLUMEEXCEPTION_H_
#define SRC_MAIN_ENTITIES_INVALIDALCOHOLBYVOLUMEEXCEPTION_H_

#include "EntityException.h"

namespace KegeratorDisplay {

class InvalidAlcoholByVolumeException : public EntityException {
public:
	InvalidAlcoholByVolumeException(const std::string& message) :
		EntityException(message) {};
	virtual ~InvalidAlcoholByVolumeException() throw() {};
};

}

#endif
