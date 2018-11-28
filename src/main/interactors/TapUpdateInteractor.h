#ifndef SRC_MAIN_INTERACTORS_TAPUPDATEINTERACTOR_H_
#define SRC_MAIN_INTERACTORS_TAPUPDATEINTERACTOR_H_

namespace KegeratorDisplay {

class Presenter;
class Storage;

class TapUpdateInteractor {
public:
	TapUpdateInteractor(Presenter* observer, Storage* storage);
	virtual ~TapUpdateInteractor();

private:
	Presenter* m_observer;
	Storage* m_storage;
};

}

#endif
