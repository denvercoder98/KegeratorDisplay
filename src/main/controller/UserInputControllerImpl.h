#ifndef SRC_MAIN_CONTROLLER_USERINPUTCONTROLLERIMPL_H_
#define SRC_MAIN_CONTROLLER_USERINPUTCONTROLLERIMPL_H_

#include "UserInputController.h"
#include "interactors/TapClearRequestObserver.h"
#include <string>
#include <iostream>

namespace KegeratorDisplay {

class TapClearObserver;

class UserInputControllerImpl : public UserInputController
{
public:
    UserInputControllerImpl(TapClearRequestObserver* observer);
    virtual ~UserInputControllerImpl();

    void clearTap(const std::string& side);

private:
    TapClearRequestObserver* m_tapClearObserver;
};

}

#endif
