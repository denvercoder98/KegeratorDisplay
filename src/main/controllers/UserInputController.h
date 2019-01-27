#ifndef SRC_MAIN_CONTROLLERS_USERINPUTCONTROLLER_H_
#define SRC_MAIN_CONTROLLERS_USERINPUTCONTROLLER_H_

#include <string>
#include "DeviceTapData.h"

namespace KegeratorDisplay {

class UserInputController
{
public:
    virtual ~UserInputController() {};

    virtual void clearTap(const std::string& side) = 0;
    virtual void saveTap(const std::string& side, DeviceTapData data) = 0;
    virtual void screenTouched() = 0;
};

}

#endif
