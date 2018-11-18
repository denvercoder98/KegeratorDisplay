#ifndef SRC_MAIN_MONITOR_TAPINTERACTOR_H_
#define SRC_MAIN_MONITOR_TAPINTERACTOR_H_

namespace KegeratorDisplay {

class Storage;

class TapInteractor {
public:
	TapInteractor(Storage* stroage);
	virtual ~TapInteractor();

private:
	Storage* m_storage;
};

}

#endif /* SRC_MAIN_MONITOR_TAPINTERACTOR_H_ */
