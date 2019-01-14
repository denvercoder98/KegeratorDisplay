#ifndef SRC_MAIN_CONTROLLERS_ANALOGDIGITALCONVERTERSENSORCONTROLLER_H_
#define SRC_MAIN_CONTROLLERS_ANALOGDIGITALCONVERTERSENSORCONTROLLER_H_

#include "SensorController.h"

namespace KegeratorDisplay {

class AnalogDigitalConverterSensor;
class AnalogDigitalConverterUpdateRequestObserver;

class AnalogDigitalConverterSensorController : public SensorController
{
public:
    enum Bits { ADC_10BITS = 10 };
    enum Channel { ADC_CHANNEL0 = 0,
                   ADC_CHANNEL1 = 1,
                   ADC_CHANNEL2 = 2,
                   ADC_CHANNEL3 = 3,
                   ADC_CHANNEL4 = 4,
                   ADC_CHANNEL5 = 5,
                   ADC_CHANNEL6 = 6,
                   ADC_CHANNEL7 = 7 };

    AnalogDigitalConverterSensorController(Bits bits,
                                           Channel channel,
                                           AnalogDigitalConverterSensor* sensor,
                                           AnalogDigitalConverterUpdateRequestObserver* observer);
    virtual ~AnalogDigitalConverterSensorController();

    void process();

private:
    Channel m_channel;
    AnalogDigitalConverterSensor* m_sensor;
    AnalogDigitalConverterUpdateRequestObserver* m_observer;
};

}

#endif
