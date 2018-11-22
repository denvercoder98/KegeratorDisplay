#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>

#include "view/CliView.h"

#include "monitor/TemperatureInteractor.h"

#include "presenter/PrintPresenter.h"

#include "storage/BlackholeStorage.h"

#include "controller/DS18B20SensorReaderStaticValue.h"
#include "controller/DS18B20Sensor.h"
#include "controller/TemperatureSensor.h"
#include "controller/TemperatureSensorController.h"
#include "controller/SensorSampler.h"

using namespace KegeratorDisplay;

int main(int argc, char** argv)
{
	PrintView* view = new CliView();
	PrintViewModel* viewModel = new PrintViewModel();
	PrintPresenter* presenter = new PrintPresenter(view, viewModel);

	Storage* storage = new BlackholeStorage();

	TemperatureInteractor* interactor = new TemperatureInteractor(presenter, storage);

	DS18B20SensorReader* ds18bSensorReader = new DS18B20SensorReaderStaticValue();
	TemperatureSensor* temperatureSensor = new DS18B20Sensor(ds18bSensorReader);
	TemperatureSensorController* temperatureSensorController = new TemperatureSensorController(temperatureSensor, interactor);

	SensorSampler* sensorSampler = new SensorSampler();
	sensorSampler->addSensorController(temperatureSensorController);
	sensorSampler->sample();

    std::cout << "main" << std::endl;

    delete sensorSampler;
    delete interactor;
    delete storage;
    delete presenter;

    return 0;
}
