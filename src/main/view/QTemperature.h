#ifndef SRC_MAIN_VIEW_QTEMPERATURE_H_
#define SRC_MAIN_VIEW_QTEMPERATURE_H_

#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QTemperature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QString unit READ unit WRITE setUnit NOTIFY unitChanged)

public:
    void setTemperature(const QString &a)
    {
        if (a != m_temperature) {
            m_temperature = a;
            emit temperatureChanged();
        }
    }

    QString temperature() const
    {
        return m_temperature;
    }

    void setUnit(const QString &a)
    {
        if (a != m_unit) {
            m_unit = a;
            emit unitChanged();
        }
    }

    QString unit() const
    {
        return m_unit;
    }

signals:
    void temperatureChanged();
    void unitChanged();

private:
    QString m_temperature;
    QString m_unit;
};

}

#endif
