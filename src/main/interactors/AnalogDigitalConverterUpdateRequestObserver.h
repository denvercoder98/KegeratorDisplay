#ifndef SRC_MAIN_INTERACTORS_ANALOGDIGITALCONVERTERUPDATEREQUESTOBSERVER_H_
#define SRC_MAIN_INTERACTORS_ANALOGDIGITALCONVERTERUPDATEREQUESTOBSERVER_H_

#include "AdcReading10Bit.h"

namespace KegeratorDisplay {

class AnalogDigitalConverterUpdateRequestObserver
{
public:
    virtual ~AnalogDigitalConverterUpdateRequestObserver() {};

    virtual void updateValue(const AdcReading10Bit& value) = 0;
};

}

#endif
