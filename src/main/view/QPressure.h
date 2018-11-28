#ifndef SRC_MAIN_VIEW_QPRESSURE_H_
#define SRC_MAIN_VIEW_QPRESSURE_H_

#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QPressure : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString pressure READ pressure WRITE setPressure NOTIFY pressureChanged)
    Q_PROPERTY(QString unit READ unit WRITE setUnit NOTIFY unitChanged)

public:
    void setPressure(const QString &a)
    {
        if (a != m_pressure) {
            m_pressure = a;
            emit pressureChanged();
        }
    }

    QString pressure() const
    {
        return m_pressure;
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
    void pressureChanged();
    void unitChanged();

private:
    QString m_pressure;
    QString m_unit;
};

}

#endif
