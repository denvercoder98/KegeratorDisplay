#ifndef SRC_MAIN_MONITOR_KEGERATOR_H
#define SRC_MAIN_MONITOR_KEGERATOR_H

namespace KegeratorDisplay {

class Tap;

class Kegerator
{
public:
    Kegerator(Tap* leftTap, Tap* rightTap);
    virtual ~Kegerator();

private:
    Tap* m_leftTap;
    Tap* m_rightTap;
};

}

#endif
