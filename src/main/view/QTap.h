#ifndef SRC_MAIN_VIEW_QTAP_H_
#define SRC_MAIN_VIEW_QTAP_H_

#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QTap : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString side READ side WRITE setSide NOTIFY sideChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString estVolume READ estVolume WRITE setEstVolume NOTIFY estVolumeChanged)
    Q_PROPERTY(QString brewer READ brewer WRITE setBrewer NOTIFY brewerChanged)
    Q_PROPERTY(QString abv READ abv WRITE setAbv NOTIFY abvChanged)
    Q_PROPERTY(QString ibu READ ibu WRITE setIbu NOTIFY ibuChanged)
    Q_PROPERTY(QString brewDate READ brewDate WRITE setBrewDate NOTIFY brewDateChanged)
    Q_PROPERTY(QString tapDate READ tapDate WRITE setTapDate NOTIFY tapDateChanged)
    Q_PROPERTY(QString finalGravity READ finalGravity WRITE setFinalGravity NOTIFY finalGravityChanged)
    Q_PROPERTY(bool buttonsVisible READ buttonsVisible WRITE setButtonsVisible NOTIFY buttonsVisibleChanged)

public:
    void setSide(const QString &a)
    {
        if (a != m_side) {
            m_side = a;
            emit sideChanged();
        }
    }

    QString side() const
    {
        return m_side;
    }

    void setName(const QString &a)
    {
        if (a != m_name) {
            m_name = a;
            emit nameChanged();
        }
    }

    QString name() const
    {
        return m_name;
    }

    void setEstVolume(const QString &a)
    {
        if (a != m_estVolume) {
            m_estVolume = a;
            emit estVolumeChanged();
        }
    }

    QString estVolume() const
    {
        return m_estVolume;
    }

    void setBrewer(const QString &a)
    {
        if (a != m_brewer) {
            m_brewer = a;
            emit brewerChanged();
        }
    }

    QString brewer() const
    {
        return m_brewer;
    }

    void setAbv(const QString &a)
    {
        if (a != m_abv) {
            m_abv = a;
            emit abvChanged();
        }
    }

    QString abv() const
    {
        return m_abv;
    }

    void setIbu(const QString &a)
    {
        if (a != m_ibu) {
            m_ibu = a;
            emit ibuChanged();
        }
    }

    QString ibu() const
    {
        return m_ibu;
    }

    void setTapDate(const QString &a)
    {
        if (a != m_tapDate) {
            m_tapDate = a;
            emit tapDateChanged();
        }
    }

    QString tapDate() const
    {
        return m_tapDate;
    }

    void setBrewDate(const QString &a)
    {
        if (a != m_brewDate) {
            m_brewDate = a;
            emit brewDateChanged();
        }
    }

    QString brewDate() const
    {
        return m_brewDate;
    }

    void setFinalGravity(const QString &a)
    {
        if (a != m_finalGravity) {
            m_finalGravity = a;
            emit finalGravityChanged();
        }
    }

    QString finalGravity() const
    {
        return m_finalGravity;
    }

    void setButtonsVisible(const bool a)
    {
        if (a != m_buttonsVisible) {
            m_buttonsVisible = a;
            emit buttonsVisibleChanged();
        }
    }

    bool buttonsVisible() const
    {
        return m_buttonsVisible;
    }

signals:
    void sideChanged();
    void nameChanged();
    void estVolumeChanged();
    void brewerChanged();
    void abvChanged();
    void ibuChanged();
    void brewDateChanged();
    void tapDateChanged();
    void finalGravityChanged();
    void buttonsVisibleChanged();

private:
    QString m_side;
    QString m_name;
    QString m_estVolume;
    QString m_brewer;
    QString m_abv;
    QString m_ibu;
    QString m_tapDate;
    QString m_brewDate;
    QString m_finalGravity;
    bool m_buttonsVisible;
};

}

#endif
