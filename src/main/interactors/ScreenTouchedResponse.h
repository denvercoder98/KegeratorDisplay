#ifndef SRC_MAIN_INTERACTORS_SCREENTOUCHEDRESPONSE_H_
#define SRC_MAIN_INTERACTORS_SCREENTOUCHEDRESPONSE_H_

namespace KegeratorDisplay {

class ScreenTouchedResponse
{
public:
    ScreenTouchedResponse(bool buttonsEnabled) :
        m_buttonsEnabled(buttonsEnabled)
    {
    }

    virtual ~ScreenTouchedResponse()
    {
    }

    bool buttonsEnabled() const
    {
        return m_buttonsEnabled;
    }

    bool operator==(const ScreenTouchedResponse& other) const
    {
        return m_buttonsEnabled == other.m_buttonsEnabled;
    }

private:
    bool m_buttonsEnabled;
};

}

#endif
