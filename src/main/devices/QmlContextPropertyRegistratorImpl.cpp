#include "QmlContextPropertyRegistratorImpl.h"
#include <QtQml/qqmlcontext.h>

namespace KegeratorDisplay {

QmlContextPropertyRegistratorImpl::QmlContextPropertyRegistratorImpl(QQmlApplicationEngine& engine) :
    m_engine(engine)
{
}

QmlContextPropertyRegistratorImpl::~QmlContextPropertyRegistratorImpl()
{
}

void QmlContextPropertyRegistratorImpl::setContextProperty(const std::string& name, QObject* object)
{
    QString qString(name.c_str());
    m_engine.rootContext()->setContextProperty(qString, object);
}

}
