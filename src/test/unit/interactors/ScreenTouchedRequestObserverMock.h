#ifndef SRC_TEST_UNIT_INTERACTORS_SCREENTOUCHEDREQUESTOBSERVERMOCK_H_
#define SRC_TEST_UNIT_INTERACTORS_SCREENTOUCHEDREQUESTOBSERVERMOCK_H_

#include "interactors/ScreenTouchedRequestObserver.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class ScreenTouchedRequestObserverMock : public ScreenTouchedRequestObserver
{
public:
    MOCK_METHOD1(handleRequest, void(const ScreenTouchedRequest& request));
};

}

#endif
