#ifndef SRC_MAIN_CONTROLLERS_USERINPUTCONTROLLERIMPL_H_
#define SRC_MAIN_CONTROLLERS_USERINPUTCONTROLLERIMPL_H_

#include "UserInputController.h"
#include <string>
#include <iostream>

namespace KegeratorDisplay {

class ApplicationThread;
class TapClearRequestObserver;
class ScreenTouchedRequestObserver;
class TapClearRequest;
class ScreenTouchedRequest;

class UserInputControllerImpl : public UserInputController
{
public:
    UserInputControllerImpl(ApplicationThread& appThread,
                            TapClearRequestObserver& tapClearObserver,
                            ScreenTouchedRequestObserver& screenObserver);
    virtual ~UserInputControllerImpl();

    void clearTap(const std::string& side);
    void saveTap(const std::string& side) {};
    void screenTouched();

private:
    void notifyTapClearRequestObserver(const TapClearRequest& request);
    void notifyScreenTouchedRequestObserver(const ScreenTouchedRequest& request);

    ApplicationThread& m_appThread;
    TapClearRequestObserver& m_tapClearObserver;
    ScreenTouchedRequestObserver& m_screenTouchedObserver;
};

}

#endif
