#ifndef SRC_MAIN_DEVICES_ACCEPTANCETESTINPUTDEVICE_H_
#define SRC_MAIN_DEVICES_ACCEPTANCETESTINPUTDEVICE_H_

namespace KegeratorDisplay {

class UserInputController;

class AcceptanceTestInputDevice
{
public:
    AcceptanceTestInputDevice(UserInputController* userInputController);
    virtual ~AcceptanceTestInputDevice();

    void clearLeftTapPressed();

private:
    UserInputController* m_userInputController;
};

}

#endif
