#ifndef SRC_TEST_UNIT_DEVICES_QMLCONTEXTPROPERTYREGISTRATORMOCK_H_
#define SRC_TEST_UNIT_DEVICES_QMLCONTEXTPROPERTYREGISTRATORMOCK_H_

#include "devices/QmlContextPropertyRegistrator.h"
#include <gmock/gmock.h>

namespace KegeratorDisplay {

class QmlContextPropertyRegistratorMock : public QmlContextPropertyRegistrator
{
public:
    MOCK_METHOD2(setContextProperty, void(const std::string&, QObject*));
};

}

#endif
