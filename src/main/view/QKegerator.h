#ifndef SRC_MAIN_VIEW_QHEADING_H_
#define SRC_MAIN_VIEW_QHEADING_H_

#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QKegerator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString heading READ heading WRITE setHeading NOTIFY headingChanged)

public:
    void setHeading(const QString &a)
    {
        if (a != m_heading) {
            m_heading = a;
            emit headingChanged();
        }
    }

    QString heading() const
    {
        return m_heading;
    }

signals:
    void headingChanged();

private:
    QString m_heading;
};

}

#endif
