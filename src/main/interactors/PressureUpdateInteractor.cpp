#include "PressureUpdateInteractor.h"
#include "Presenter.h"

namespace KegeratorDisplay {

PressureUpdateInteractor::PressureUpdateInteractor(Presenter& presenter) :
    m_presenter(presenter)
{
}

PressureUpdateInteractor::~PressureUpdateInteractor()
{
}

void PressureUpdateInteractor::updateValue(const AdcReading10Bit& value)
{
    RelativePressureBar pressure(1);
    PressureUpdateResponse update(pressure);
    m_presenter.updatePressure(update);
}

}
