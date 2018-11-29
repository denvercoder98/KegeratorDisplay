#include <interactors/TapClearRequest.h>

namespace KegeratorDisplay {

TapClearRequest::TapClearRequest(const TapSide side) :
    m_tapSide(side)
{
}

TapClearRequest::~TapClearRequest()
{
}

const TapSide TapClearRequest::tapSide() const
{
    return m_tapSide;
}

}
