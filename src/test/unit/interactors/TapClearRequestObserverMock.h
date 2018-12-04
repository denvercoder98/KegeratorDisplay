#ifndef SRC_TEST_INTERACTORS_TAPCLEARREQUESTOBSERVERMOCK_H_
#define SRC_TEST_INTERACTORS_TAPCLEARREQUESTOBSERVERMOCK_H_

#include <interactors/TapClearRequestObserver.h>

namespace KegeratorDisplay {

class TapClearRequestObserverMock: public TapClearRequestObserver
{
public:
    MOCK_METHOD1(handleRequest, void(const TapClearRequest&));
};

}

#endif
