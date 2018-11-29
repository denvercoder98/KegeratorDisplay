#include "TapClearInteractor.h"
#include "TapClearResponse.h"
#include "Storage.h"
#include "Presenter.h"

namespace KegeratorDisplay {

TapClearInteractor::TapClearInteractor(Presenter* presenter, Storage* storage) :
    m_presenter(presenter),
    m_storage(storage)
{
}

TapClearInteractor::~TapClearInteractor()
{
}

void TapClearInteractor::handleRequest(const TapClearRequest& request)
{
    clearStorage(request.tapSide());
    updatePresenter(request.tapSide());
}

void TapClearInteractor::clearStorage(TapSide side)
{
    if (side == TAP_LEFT)
    {
        m_storage->clearLeftTap();
    } else if (side == TAP_RIGHT)
    {
        m_storage->clearRightTap();
    }
}

void TapClearInteractor::updatePresenter(TapSide side)
{
    TapClearResponse response(side);
    m_presenter->clearTap(response);
}

}
