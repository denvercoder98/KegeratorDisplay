#ifndef SRC_MAIN_INTERACTORS_SCREENTOUCHEDREQUESTOBSERVER_H_
#define SRC_MAIN_INTERACTORS_SCREENTOUCHEDREQUESTOBSERVER_H_

#include "ScreenTouchedRequest.h"

namespace KegeratorDisplay {

class ScreenTouchedRequestObserver
{
public:
    virtual ~ScreenTouchedRequestObserver() {};

    virtual void handleRequest(const ScreenTouchedRequest& request) = 0;
};

}

#endif
