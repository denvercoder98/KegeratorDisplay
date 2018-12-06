#ifndef SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_

#include <string>

namespace KegeratorDisplay {

class GuiViewModel
{
public:
    class TapViewModel {
    public:
        std::string beerName = "";
        std::string brewerName = "";
        std::string abv = "";
        std::string ibu = "";
        std::string brewDate = "";
        std::string tapDate = "";
        std::string fg = "";

        bool operator==(const TapViewModel& other) const
        {
            return beerName == other.beerName &&
                brewerName == other.brewerName &&
                abv == other.abv &&
                ibu == other.ibu &&
                brewDate == other.brewDate &&
                tapDate == other.tapDate &&
                fg == other.fg;
        }
    };

    std::string temperature = "";
    TapViewModel leftTap;
    TapViewModel rightTap;

    bool operator==(const GuiViewModel& other) const
    {
        return
            temperature == other.temperature &&
            leftTap == other.leftTap &&
            rightTap == other.rightTap;
    }
};

}

#endif
