#ifndef SRC_MAIN_PRESENTER_PRINTVIEW_H
#define SRC_MAIN_PRESENTER_PRINTVIEW_H

#include "PrintViewModel.h"

namespace KegeratorDisplay {

class PrintView
{
public:
    virtual ~PrintView() {};

    virtual void updateView(const PrintViewModel& viewModel) = 0;
};

}

#endif
