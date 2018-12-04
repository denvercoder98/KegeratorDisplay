#include "GuiKegerator.h"

int main(int argc, char** argv)
{
    KegeratorDisplay::GuiKegerator kegerator;
    kegerator.start(argc, argv);
    kegerator.stop();

    return 0;
}
