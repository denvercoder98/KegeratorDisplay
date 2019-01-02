#ifndef SRC_MAIN_PRESENTER_GUIVIEW_H_
#define SRC_MAIN_PRESENTER_GUIVIEW_H_

#include "GuiViewModel.h"
#include "GuiViewTemperatureModel.h"

namespace KegeratorDisplay {

class GuiView
{
public:
    virtual ~GuiView() {};

    virtual void updateView(const GuiViewModel& view) = 0;
    virtual void updateTemperature(const GuiViewTemperatureModel& view) = 0;
    virtual void run() = 0;
};

}

#endif
