#ifndef SRC_MAIN_PRESENTER_PRESSUREVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_PRESSUREVIEWMODEL_H_

#include <string>

namespace KegeratorDisplay {

class PressureViewModel
{
public:
    std::string pressure = "";
    std::string unit = "";
    std::string tag = "CO2: ";
};

}

#endif
