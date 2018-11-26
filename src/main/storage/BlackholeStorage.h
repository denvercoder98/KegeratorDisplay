#ifndef SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_
#define SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_

#include "monitor/Storage.h"

namespace KegeratorDisplay {

class BlackholeStorage: public Storage {
public:
	BlackholeStorage();
	virtual ~BlackholeStorage();

	Temperature* readTemperature();
	void writeTemperature(Temperature*);
    Tap* readLeftTap();
    void writeLeftTap(Tap*);
    Tap* readRightTap();
    void writeRightTap(Tap*);
};

}

#endif /* SRC_MAIN_STORAGE_BLACKHOLESTORAGE_H_ */
