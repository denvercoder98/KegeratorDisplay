#ifndef SRC_TEST_UNIT_CONTROLLER_USERINPUTCONTROLLERMOCK_H_
#define SRC_TEST_UNIT_CONTROLLER_USERINPUTCONTROLLERMOCK_H_

#include "controllers/UserInputController.h"

#include <gmock/gmock.h>

namespace KegeratorDisplay {

class UserInputControllerMock : public UserInputController
{
public:
    MOCK_METHOD1(clearTap, void(const std::string&));
    MOCK_METHOD1(saveTap, void(const std::string&));
    MOCK_METHOD0(screenTouched, void());
};

}

#endif
