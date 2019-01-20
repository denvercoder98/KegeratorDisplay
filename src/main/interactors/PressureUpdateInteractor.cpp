#include "PressureUpdateInteractor.h"
#include "Presenter.h"

#define PRESSURE_READING_VOLTAGE_MIN 0.33
#define PRESSURE_READING_VOLTAGE_MAX 3.0
#define ADC_VOLTAGE_MAX              3.3
#define ADC_READING_MAX              1024
#define PSI_TO_BAR                   0.0689
#define PRESSURE_PSI_MAX             100

#define ADC_PRESSURE_READING_ZERO     (PRESSURE_READING_VOLTAGE_MIN/ADC_VOLTAGE_MAX) * ADC_READING_MAX
#define ADC_PRESSURE_READING_MAX      (PRESSURE_READING_VOLTAGE_MAX/ADC_VOLTAGE_MAX) * ADC_READING_MAX
#define ADC_PSI_PER_READING_INCREMENT PRESSURE_PSI_MAX / (ADC_PRESSURE_READING_MAX - ADC_PRESSURE_READING_ZERO)

namespace KegeratorDisplay {

PressureUpdateInteractor::PressureUpdateInteractor(Presenter& presenter) :
    m_presenter(presenter)
{
}

PressureUpdateInteractor::~PressureUpdateInteractor()
{
}

Bar PressureUpdateInteractor::linearVoltageReadingToBar(const AdcReading10Bit& reading)
{
    //TODO Throw if value is below 102 or above 931
    return Bar((reading.value() - ADC_PRESSURE_READING_ZERO) * ADC_PSI_PER_READING_INCREMENT * PSI_TO_BAR);
}

void PressureUpdateInteractor::updateValue(const AdcReading10Bit& reading)
{
    Bar pressure = linearVoltageReadingToBar(reading);
    PressureUpdateResponse update(pressure);
    m_presenter.updatePressure(update);
}

}
