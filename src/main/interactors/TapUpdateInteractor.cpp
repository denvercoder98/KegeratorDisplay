#include "Presenter.h"
#include "Storage.h"
#include "TapUpdateInteractor.h"
#include "TapUpdateResponse.h"
#include "entities/Beer.h"

namespace KegeratorDisplay {

TapUpdateInteractor::TapUpdateInteractor(Presenter& presenter, Storage& storage) :
    m_presenter(presenter),
    m_storage(storage)
{
    readAndUpdateTap(TAP_LEFT);
    readAndUpdateTap(TAP_RIGHT);
}

TapUpdateInteractor::~TapUpdateInteractor()
{
}

void TapUpdateInteractor::updateTap(const TapUpdateRequest& request)
{
}

void TapUpdateInteractor::readAndUpdateTap(const TapSide side)
{
    Tap* tap;
    if (side == TAP_LEFT) {
        tap = m_storage.readLeftTap();
    }
    else if (side == TAP_RIGHT) {
        tap = m_storage.readRightTap();
    }
    else {
        //TODO throw
    }
    Beer beer = tap->beer();
    BeerUpdateResponse beerUpdate(beer.name(),
                          beer.brewerName(),
                          beer.alcoholByVolume().value(),
                          beer.internationalBitternessUnits().value(),
                          beer.brewDate().value(),
                          beer.tapDate().value(),
                          beer.finalGravity().value());

    TapUpdateResponse tapUpdate(side, beerUpdate, tap->isEmpty());
    m_presenter.updateTap(tapUpdate);
    delete tap;
}

}
