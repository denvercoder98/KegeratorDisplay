#ifndef SRC_MAIN_DEVICES_QMLCONTEXTPROPERTYREGISTRATOR_H_
#define SRC_MAIN_DEVICES_QMLCONTEXTPROPERTYREGISTRATOR_H_

#include <string>
#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QmlContextPropertyRegistrator
{
public:
    virtual ~QmlContextPropertyRegistrator() {};

    virtual void setContextProperty(const std::string& name, QObject* object) = 0;
};

}

#endif
