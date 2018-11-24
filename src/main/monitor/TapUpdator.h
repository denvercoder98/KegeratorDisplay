#ifndef SRC_MAIN_MONITOR_TAPUPDATOR_H_
#define SRC_MAIN_MONITOR_TAPUPDATOR_H_

namespace KegeratorDisplay {

class KegeratorObserver;
class Storage;

class TapUpdator {
public:
	TapUpdator(KegeratorObserver* observer, Storage* storage);
	virtual ~TapUpdator();

private:
	KegeratorObserver* m_observer;
	Storage* m_storage;
};

}

#endif
