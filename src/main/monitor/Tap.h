#ifndef SRC_MAIN_MONITOR_TAP_H
#define SRC_MAIN_MONITOR_TAP_H

class Beer;

class Tap
{
public:
    Tap();

private:
    Beer* m_beer;
};

#endif