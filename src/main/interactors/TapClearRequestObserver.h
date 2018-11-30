#ifndef SRC_MAIN_INTERACTORS_TAPCLEARREQUESTOBSERVER_H_
#define SRC_MAIN_INTERACTORS_TAPCLEARREQUESTOBSERVER_H_

#include "TapClearRequest.h"

namespace KegeratorDisplay {

class TapClearRequestObserver
{
public:
    virtual ~TapClearRequestObserver() {}

    virtual void handleRequest(const TapClearRequest& request) = 0;
};

}

#endif
