#ifndef SRC_MAIN_INTERACTORS_TAPCLEARREQUEST_H_
#define SRC_MAIN_INTERACTORS_TAPCLEARREQUEST_H_

#include "TapSide.h"

namespace KegeratorDisplay {

class TapClearRequest
{
public:
    TapClearRequest(const TapSide side);
    virtual ~TapClearRequest();

    const TapSide tapSide() const;

private:
    const TapSide m_tapSide;
};

}

#endif
