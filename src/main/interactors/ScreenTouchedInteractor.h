#ifndef SRC_MAIN_INTERACTORS_SCREENTOUCHEDINTERACTOR_H_
#define SRC_MAIN_INTERACTORS_SCREENTOUCHEDINTERACTOR_H_

#include "ScreenTouchedRequestObserver.h"
#include <thread/DeadlineTimer.h>

namespace KegeratorDisplay {

class DeadlineTimer;
class Presenter;

class ScreenTouchedInteractor : public ScreenTouchedRequestObserver
{
public:
    ScreenTouchedInteractor(unsigned int doubleTapWindowSeconds,
                            DeadlineTimer* timer,
                            Presenter& presenter);
    virtual ~ScreenTouchedInteractor();

    void handleRequest(const ScreenTouchedRequest& request);

    void stuffHappened(const boost::system::error_code& error);

private:
    DeadlineTimer* m_timer;
    bool m_tappedOnce;
    Presenter& m_presenter;
};

}

#endif
