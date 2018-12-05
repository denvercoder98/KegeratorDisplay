#ifndef SRC_MAIN_KEGERATOR_H_
#define SRC_MAIN_KEGERATOR_H_

#include "interactors/TapUpdateInteractor.h"
#include "interactors/TapClearInteractor.h"
#include "interactors/TemperatureUpdateInteractor.h"
#include "controller/TemperatureSensorController.h"
#include "thread/BoostDeadlineTimer.h"
#include "thread/BoostMutex.h"

#include <boost/asio/io_service.hpp>
#include <boost/thread.hpp>

namespace KegeratorDisplay {

class Storage;
class Presenter;
class View;
class UserInputController;
class SensorSampler;
class GuiView;

class Kegerator
{
public:
    Kegerator();
    virtual ~Kegerator();

    void start(int &argc, char** argv);
    void stop();

protected:
    virtual void createStorage();
    virtual void createView(int &argc, char** argv) = 0;
    virtual void createPresenter();
    virtual void createInteractors();
    virtual void createControllers();
    virtual void createDevices() = 0;

    UserInputController* getUserInputController() const;
    void setPresenter(Presenter* presenter);

    virtual void run() = 0;

    GuiView* p_view;

private:
    TemperatureSensorController* createTemperatureSensorController(TemperatureUpdateInteractor* temperatureUpdateInteractor);
    UserInputController* createUserInputController(TapClearInteractor* tapClearInteractor);
    void workerThread();

    Presenter* m_presenter;
    Storage* m_storage;
    TemperatureUpdateInteractor* m_temperatureUpdateInteractor;
    TapUpdateInteractor* m_tapUpdateInteractor;
    TapClearInteractor* m_tapClearInteractor;
    TemperatureSensorController* m_temperatureSensorController;
    UserInputController* m_userInputController;
    boost::asio::io_service* m_ioService;
    boost::asio::io_service::work* m_work;
    boost::thread* m_thread;
    SensorSampler* m_sensorSampler;
    bool m_started;
};

}

#endif
