#include "AnalogDigitalConverterSensor.h"
#include "AnalogDigitalConverterSensorController.h"
#include "InvalidAnalogDigitalConverterSensorControllerArgumentException.h"
#include "interactors/AnalogDigitalConverterUpdateRequestObserver.h"

namespace KegeratorDisplay {

AnalogDigitalConverterSensorController::AnalogDigitalConverterSensorController(Bits bits,
                                                                               Channel channel,
                                                                               AnalogDigitalConverterSensor* sensor,
                                                                               AnalogDigitalConverterUpdateRequestObserver& observer) :
    m_sensor(sensor),
    m_observer(observer),
    m_channel(channel)
{
    if (sensor == NULL) {
        throw InvalidAnalogDigitalConverterSensorControllerArgumentException("Missing sensor dependency");
    }
}

AnalogDigitalConverterSensorController::~AnalogDigitalConverterSensorController()
{
    delete m_sensor;
}

void AnalogDigitalConverterSensorController::process()
{
    unsigned int value = m_sensor->readChannel(m_channel);
    // TODO catch and log exception
    AdcReading10Bit reading(value);
    m_observer.updateValue(reading);
}

}
