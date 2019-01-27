#ifndef SRC_TEST_UNIT_INTERACTORS_TAPUPDATEREQUESTOBSERVERMOCK_H_
#define SRC_TEST_UNIT_INTERACTORS_TAPUPDATEREQUESTOBSERVERMOCK_H_

#include "interactors/TapUpdateRequestObserver.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class TapUpdateRequestObserverMock : public TapUpdateRequestObserver
{
public:
    MOCK_METHOD1(updateTap, void(const TapUpdateRequest& request));
};

}

#endif
