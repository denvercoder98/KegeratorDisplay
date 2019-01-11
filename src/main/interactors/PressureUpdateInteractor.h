#ifndef SRC_MAIN_INTERACTORS_PRESSUREUPDATEINTERACTOR_H_
#define SRC_MAIN_INTERACTORS_PRESSUREUPDATEINTERACTOR_H_

#include "AnalogDigitalConverterUpdateRequestObserver.h"

namespace KegeratorDisplay {

class Presenter;

class PressureUpdateInteractor : public AnalogDigitalConverterUpdateRequestObserver
{
public:
    PressureUpdateInteractor(Presenter& presenter);
    virtual ~PressureUpdateInteractor();

    void updateValue(const AdcReading10Bit& value);

private:
    Presenter& m_presenter;
};

}

#endif
