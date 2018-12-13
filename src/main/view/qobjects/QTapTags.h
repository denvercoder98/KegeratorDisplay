#ifndef SRC_MAIN_VIEW_QTAPTAGS_H_
#define SRC_MAIN_VIEW_QTAPTAGS_H_

#include <QtCore/qobject.h>

namespace KegeratorDisplay {

class QTapTags : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nameTag READ nameTag WRITE setNameTag NOTIFY nameTagChanged)
    Q_PROPERTY(QString estVolumeTag READ estVolumeTag WRITE setEstVolumeTag NOTIFY estVolumeTagChanged)
    Q_PROPERTY(QString brewerTag READ brewerTag WRITE setBrewerTag NOTIFY brewerTagChanged)
    Q_PROPERTY(QString abvTag READ abvTag WRITE setAbvTag NOTIFY abvTagChanged)
    Q_PROPERTY(QString ibuTag READ ibuTag WRITE setIbuTag NOTIFY ibuTagChanged)
    Q_PROPERTY(QString brewDateTag READ brewDateTag WRITE setBrewDateTag NOTIFY brewDateTagChanged)
    Q_PROPERTY(QString tapDateTag READ tapDateTag WRITE setTapDateTag NOTIFY tapDateTagChanged)
    Q_PROPERTY(QString finalGravityTag READ finalGravityTag WRITE setFinalGravityTag NOTIFY finalGravityTagChanged)
    Q_PROPERTY(QString clearButtonTag READ clearButtonTag WRITE setClearButtonTag NOTIFY clearButtonTagChanged)

public:
    void setNameTag(const QString &a)
    {
        if (a != m_nameTag) {
            m_nameTag = a;
            emit nameTagChanged();
        }
    }

    QString nameTag() const
    {
        return m_nameTag;
    }

    void setEstVolumeTag(const QString &a)
    {
        if (a != m_estVolumeTag) {
            m_estVolumeTag = a;
            emit estVolumeTagChanged();
        }
    }

    QString estVolumeTag() const
    {
        return m_estVolumeTag;
    }

    void setBrewerTag(const QString &a)
    {
        if (a != m_brewerTag) {
            m_brewerTag = a;
            emit brewerTagChanged();
        }
    }

    QString brewerTag() const
    {
        return m_brewerTag;
    }

    void setAbvTag(const QString &a)
    {
        if (a != m_abvTag) {
            m_abvTag = a;
            emit abvTagChanged();
        }
    }

    QString abvTag() const
    {
        return m_abvTag;
    }

    void setIbuTag(const QString &a)
    {
        if (a != m_ibuTag) {
            m_ibuTag = a;
            emit ibuTagChanged();
        }
    }

    QString ibuTag() const
    {
        return m_ibuTag;
    }

    void setTapDateTag(const QString &a)
    {
        if (a != m_tapDateTag) {
            m_tapDateTag = a;
            emit tapDateTagChanged();
        }
    }

    QString tapDateTag() const
    {
        return m_tapDateTag;
    }

    void setBrewDateTag(const QString &a)
    {
        if (a != m_brewDateTag) {
            m_brewDateTag = a;
            emit brewDateTagChanged();
        }
    }

    QString brewDateTag() const
    {
        return m_brewDateTag;
    }

    void setFinalGravityTag(const QString &a)
    {
        if (a != m_finalGravityTag) {
            m_finalGravityTag = a;
            emit finalGravityTagChanged();
        }
    }

    QString finalGravityTag() const
    {
        return m_finalGravityTag;
    }

    void setClearButtonTag(const QString &a)
    {
        if (a != m_clearButtonTag) {
            m_clearButtonTag = a;
            emit clearButtonTagChanged();
        }
    }

    QString clearButtonTag() const
    {
        return m_clearButtonTag;
    }

signals:
    void nameTagChanged();
    void estVolumeTagChanged();
    void brewerTagChanged();
    void abvTagChanged();
    void ibuTagChanged();
    void brewDateTagChanged();
    void tapDateTagChanged();
    void finalGravityTagChanged();
    void clearButtonTagChanged();

private:
    QString m_nameTag;
    QString m_estVolumeTag;
    QString m_brewerTag;
    QString m_abvTag;
    QString m_ibuTag;
    QString m_tapDateTag;
    QString m_brewDateTag;
    QString m_finalGravityTag;
    QString m_clearButtonTag;
};

}

#endif
