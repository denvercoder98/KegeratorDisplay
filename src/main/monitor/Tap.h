#ifndef SRC_MAIN_MONITOR_TAP_H
#define SRC_MAIN_MONITOR_TAP_H

namespace KegeratorDisplay {

class Beer;

class Tap
{
public:
    Tap();

private:
    Beer* m_beer;
};

}

#endif
