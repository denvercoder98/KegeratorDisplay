#ifndef SRC_MAIN_GUIKEGERATOR_H_
#define SRC_MAIN_GUIKEGERATOR_H_

#include "Kegerator.h"

namespace KegeratorDisplay {

class GuiView;
class SensorSampler;

class GuiKegerator : public Kegerator
{
public:
    GuiKegerator(GuiView* view,
                 SensorSampler* sensorSampler,
                 boost::asio::io_service& ioService,
                 boost::thread& thread);
    virtual ~GuiKegerator();

protected:
    void run();

private:
    GuiView* m_view;

};

}

#endif
