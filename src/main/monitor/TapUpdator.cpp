#include "TapUpdator.h"
#include "KegeratorObserver.h"
#include "Storage.h"
#include "TapUpdate.h"
#include "Beer.h"
#include "InvalidTapUpdatorArgumentException.h"

#include <iostream>

namespace KegeratorDisplay {

TapUpdator::TapUpdator(KegeratorObserver* observer, Storage* storage) :
    m_observer(observer),
    m_storage(storage)
{
    if (m_storage == NULL) {
        throw InvalidTapUpdatorArgumentException("Missing Storage dependency");
    }

    if (m_observer == NULL) {
        throw InvalidTapUpdatorArgumentException("Missing KegeratorObserver dependency");
    }

    Tap* leftTap = m_storage->readLeftTap();
    Beer beer = leftTap->beer();
    BeerUpdate beerUpdate(beer.name(),
                          beer.brewerName(),
                          beer.alcoholByVolume().value(),
                          beer.internationalBitternessUnits().value(),
                          beer.brewDate().value(),
                          beer.tapDate().value(),
                          beer.finalGravity().value());

    TapUpdate leftTapUpdate(TAP_LEFT, beerUpdate);
    m_observer->updateTap(leftTapUpdate);
    delete leftTap;

    Tap* rightTap = m_storage->readRightTap();
    Beer beer2 = rightTap->beer();
    BeerUpdate beerUpdate2(beer2.name(),
                          beer2.brewerName(),
                          beer2.alcoholByVolume().value(),
                          beer2.internationalBitternessUnits().value(),
                          beer2.brewDate().value(),
                          beer2.tapDate().value(),
                          beer2.finalGravity().value());

    TapUpdate rightTapUpdate(TAP_RIGHT, beerUpdate2);
    m_observer->updateTap(rightTapUpdate);
    delete rightTap;
}

TapUpdator::~TapUpdator()
{
}

}
