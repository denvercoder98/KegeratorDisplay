#include "GuiKegerator.h"

int main(int argc, char** argv)
{
    KegeratorDisplay::GuiKegerator kegerator;
    kegerator.startAndRun(argc, argv);
    kegerator.stop();

    return 0;
}
