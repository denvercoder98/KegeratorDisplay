#include "TapUpdator.h"
#include "Storage.h"
#include "InvalidTapUpdatorArgumentException.h"

namespace KegeratorDisplay {

TapUpdator::TapUpdator(Storage* storage) :
    m_storage(storage),
    m_tap(NULL)
{
    if (storage == NULL) {
        throw InvalidTapUpdatorArgumentException("Missing Storage dependency");
    }

    m_tap = m_storage->readTap();
}

TapUpdator::~TapUpdator()
{
    delete m_tap;
}

}
