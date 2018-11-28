#include "Presenter.h"
#include "TapUpdateInteractor.h"
#include "TapUpdateResponse.h"
#include "Storage.h"
#include "InvalidTapUpdateInteractorArgumentException.h"
#include "entities/Beer.h"

#include <iostream>

namespace KegeratorDisplay {

TapUpdateInteractor::TapUpdateInteractor(Presenter* presenter, Storage* storage) :
    m_observer(presenter),
    m_storage(storage)
{
    if (m_storage == NULL) {
        throw InvalidTapUpdateInteractorArgumentException("Missing Storage dependency");
    }

    if (m_observer == NULL) {
        throw InvalidTapUpdateInteractorArgumentException("Missing KegeratorObserver dependency");
    }

    Tap* leftTap = m_storage->readLeftTap();
    Beer beer = leftTap->beer();
    BeerUpdateResponse beerUpdate(beer.name(),
                          beer.brewerName(),
                          beer.alcoholByVolume().value(),
                          beer.internationalBitternessUnits().value(),
                          beer.brewDate().value(),
                          beer.tapDate().value(),
                          beer.finalGravity().value());

    TapUpdateResponse leftTapUpdate(TAP_LEFT, beerUpdate);
    m_observer->updateTap(leftTapUpdate);
    delete leftTap;

    Tap* rightTap = m_storage->readRightTap();
    Beer beer2 = rightTap->beer();
    BeerUpdateResponse beerUpdate2(beer2.name(),
                          beer2.brewerName(),
                          beer2.alcoholByVolume().value(),
                          beer2.internationalBitternessUnits().value(),
                          beer2.brewDate().value(),
                          beer2.tapDate().value(),
                          beer2.finalGravity().value());

    TapUpdateResponse rightTapUpdate(TAP_RIGHT, beerUpdate2);
    m_observer->updateTap(rightTapUpdate);
    delete rightTap;
}

TapUpdateInteractor::~TapUpdateInteractor()
{
}

}
