#ifndef SRC_MAIN_CONTROLLER_USERINPUTCONTROLLERIMPL_H_
#define SRC_MAIN_CONTROLLER_USERINPUTCONTROLLERIMPL_H_

#include "UserInputController.h"
#include <string>
#include <iostream>

namespace KegeratorDisplay {

class TapClearRequestObserver;
class ScreenTouchedRequestObserver;

class UserInputControllerImpl : public UserInputController
{
public:
    UserInputControllerImpl(TapClearRequestObserver* tapClearObserver, ScreenTouchedRequestObserver* screenObserver);
    virtual ~UserInputControllerImpl();

    void clearTap(const std::string& side);
    void screenTouched();

private:
    TapClearRequestObserver* m_tapClearObserver;
    ScreenTouchedRequestObserver* m_screenTouchedObserver;
};

}

#endif
