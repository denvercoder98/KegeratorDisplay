#include "GuiKegerator.h"
#include <iostream>

int main(int argc, char** argv)
{
    try {
        KegeratorDisplay::GuiKegerator kegerator;
        kegerator.startAndRun(argc, argv);
        return 0;
    }
    catch (std::exception& ex) {
        std::cerr << "Error in application, terminating" << std::endl;
        return 1;
    }
}
