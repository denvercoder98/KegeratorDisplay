#ifndef SRC_MAIN_DEVICES_QMLCONTEXTPROPERTYREGISTRATORIMPL_H_
#define SRC_MAIN_DEVICES_QMLCONTEXTPROPERTYREGISTRATORIMPL_H_

#include "QmlContextPropertyRegistrator.h"
#include <QtQml/qqmlapplicationengine.h>

namespace KegeratorDisplay {

class QmlContextPropertyRegistratorImpl : public QmlContextPropertyRegistrator
{
public:
    QmlContextPropertyRegistratorImpl(QQmlApplicationEngine& engine);
    virtual ~QmlContextPropertyRegistratorImpl();

    void setContextProperty(const std::string& name, QObject* object);

private:
    QQmlApplicationEngine& m_engine;
};

}

#endif
