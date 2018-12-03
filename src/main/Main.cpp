#include <iostream>
#include "GuiKegerator.h"

using namespace KegeratorDisplay;

int main(int argc, char** argv)
{
    std::cout << "Test run" << std::endl;

    GuiKegerator kegerator;
    kegerator.start(argc, argv);
    kegerator.stop();

    return 0;
}
