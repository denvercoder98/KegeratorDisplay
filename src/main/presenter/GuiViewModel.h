#ifndef SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_

#include <string>

namespace KegeratorDisplay {

class GuiViewModel
{
public:
    std::string temperature = "";
    std::string leftTapBeerName = "";
    std::string leftTapBrewerName = "";
    std::string leftTapAbv = "";
    std::string leftTapIbu = "";
    std::string leftTapBrewDate = "";
    std::string leftTapTapDate = "";
    std::string leftTapFg = "";
    std::string rightTapBeerName = "";
    std::string rightTapBrewerName = "";
    std::string rightTapAbv = "";
    std::string rightTapIbu = "";
    std::string rightTapBrewDate = "";
    std::string rightTapTapDate = "";
    std::string rightTapFg = "";

    bool operator==(const GuiViewModel& other) const
    {
        return
            temperature == other.temperature &&
            leftTapBeerName == other.leftTapBeerName &&
            leftTapBrewerName == other.leftTapBrewerName &&
            leftTapAbv == other.leftTapAbv &&
            leftTapIbu == other.leftTapIbu &&
            leftTapBrewDate == other.leftTapBrewDate &&
            leftTapTapDate == other.leftTapTapDate &&
            leftTapFg == other.leftTapFg &&
            rightTapBeerName == other.rightTapBeerName &&
            rightTapBrewerName == other.rightTapBrewerName &&
            rightTapAbv == other.rightTapAbv &&
            rightTapIbu == other.rightTapIbu &&
            leftTapBrewDate == other.leftTapBrewDate &&
            leftTapTapDate == other.leftTapTapDate &&
            leftTapFg == other.leftTapFg;
    }
};

}

#endif
