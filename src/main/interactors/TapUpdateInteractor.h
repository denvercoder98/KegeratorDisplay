#ifndef SRC_MAIN_INTERACTORS_TAPUPDATEINTERACTOR_H_
#define SRC_MAIN_INTERACTORS_TAPUPDATEINTERACTOR_H_

#include "TapUpdateRequestObserver.h"

namespace KegeratorDisplay {

class Presenter;
class Storage;

class TapUpdateInteractor : public TapUpdateRequestObserver {
public:
	TapUpdateInteractor(Presenter* presenter, Storage* storage);
	virtual ~TapUpdateInteractor();

	void updateTap(const TapUpdateRequest& request);

private:
	Presenter* m_presenter;
	Storage* m_storage;
};

}

#endif
