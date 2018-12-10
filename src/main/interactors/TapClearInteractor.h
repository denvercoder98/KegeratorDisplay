#ifndef SRC_MAIN_INTERACTORS_TAPCLEARINTERACTOR_H_
#define SRC_MAIN_INTERACTORS_TAPCLEARINTERACTOR_H_

#include "TapClearRequestObserver.h"
#include "TapClearRequest.h"

namespace KegeratorDisplay {

class Presenter;
class Storage;

class TapClearInteractor : public TapClearRequestObserver
{
public:
    TapClearInteractor(Presenter& presenter, Storage& storage);
    virtual ~TapClearInteractor();

    void handleRequest(const TapClearRequest& request);

private:
    Presenter& m_presenter;
    Storage& m_storage;

    void clearStorage(TapSide side);
    void updatePresenter(TapSide side);
};

}

#endif
