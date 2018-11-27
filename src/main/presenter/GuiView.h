#ifndef SRC_MAIN_PRESENTER_GUIVIEW_H_
#define SRC_MAIN_PRESENTER_GUIVIEW_H_

#include "GuiViewModel.h"

namespace KegeratorDisplay {

class GuiView
{
public:
    virtual ~GuiView() {};

    virtual void updateView(const GuiViewModel& view) = 0;
};

}

#endif
