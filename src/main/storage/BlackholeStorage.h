#ifndef SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_
#define SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_

#include "monitor/Storage.h"

namespace KegeratorDisplay {

class BlackholeStorage: public Storage {
public:
	BlackholeStorage();
	virtual ~BlackholeStorage();

	virtual Temperature* readTemperature();
};

}

#endif /* SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_ */
