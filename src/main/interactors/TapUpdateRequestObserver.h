#ifndef SRC_MAIN_INTERACTORS_TAPUPDATEREQUESTOBSERVER_H_
#define SRC_MAIN_INTERACTORS_TAPUPDATEREQUESTOBSERVER_H_

#include "TapUpdateRequest.h"

namespace KegeratorDisplay {

class TapUpdateRequestObserver
{
public:
    virtual ~TapUpdateRequestObserver() {};

    virtual void updateTap(const TapUpdateRequest& request) = 0;
};

}

#endif
