#ifndef SRC_MAIN_MONITOR_TAPUPDATOR_H_
#define SRC_MAIN_MONITOR_TAPUPDATOR_H_

namespace KegeratorDisplay {

class Tap;
class Storage;

class TapUpdator {
public:
	TapUpdator(Storage* stroage);
	virtual ~TapUpdator();

private:
	Tap* m_tap;
	Storage* m_storage;
};

}

#endif
