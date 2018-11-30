#ifndef SRC_MAIN_CONTROLLER_USERINPUTCONTROLLER_H_
#define SRC_MAIN_CONTROLLER_USERINPUTCONTROLLER_H_

#include "interactors/TapClearRequestObserver.h"
#include <string>
#include <iostream>

namespace KegeratorDisplay {

class TapClearObserver;

class UserInputController
{
public:
    UserInputController(TapClearRequestObserver* observer);
    virtual ~UserInputController();

    void clearTap(const std::string& side);

private:
    TapClearRequestObserver* m_tapClearObserver;
};

}

#endif
