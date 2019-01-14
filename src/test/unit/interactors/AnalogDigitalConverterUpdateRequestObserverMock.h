#ifndef SRC_TEST_UNIT_INTERACTORS_ANALOGDIGITALCONVERTERUPDATEREQUESTOBSERVERMOCK_H_
#define SRC_TEST_UNIT_INTERACTORS_ANALOGDIGITALCONVERTERUPDATEREQUESTOBSERVERMOCK_H_

#include "interactors/AnalogDigitalConverterUpdateRequestObserver.h"

#include <gmock/gmock.h>

namespace KegeratorDisplay {

class AnalogDigitalConverterUpdateRequestObserverMock : public AnalogDigitalConverterUpdateRequestObserver
{
public:
    MOCK_METHOD1(updateValue, void(const AdcReading10Bit&));
};

}

#endif
