#ifndef SRC_MAIN_VIEW_VIEW_H_
#define SRC_MAIN_VIEW_VIEW_H_

namespace KegeratorDisplay {

class View
{
public:
    virtual ~View() {};

    virtual void run(int argc, char** argv) = 0;
};

}

#endif
