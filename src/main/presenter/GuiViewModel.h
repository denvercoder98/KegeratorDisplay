#ifndef SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_

#include <string>
#include <ostream>

namespace KegeratorDisplay {

class GuiViewModel
{
public:
    class TapViewModel {
    public:
        bool empty = false;
        std::string beerName = "";
        std::string brewerName = "";
        std::string abv = "";
        std::string ibu = "";
        std::string brewDate = "";
        std::string tapDate = "";
        std::string fg = "";

        bool operator==(const TapViewModel& other) const
        {
            return empty == other.empty &&
                beerName == other.beerName &&
                brewerName == other.brewerName &&
                abv == other.abv &&
                ibu == other.ibu &&
                brewDate == other.brewDate &&
                tapDate == other.tapDate &&
                fg == other.fg;
        }

        friend std::ostream& operator<<(std::ostream& stream, const TapViewModel& model)
        {
            return stream << "["
                          << "empty: " << model.empty << ", "
                          << "name: '" << model.beerName << "', "
                          << "brewerName: '" << model.brewerName << "', "
                          << "abv: '" << model.abv << "', "
                          << "ibu: '" << model.ibu << "', "
                          << "brewDate: '" << model.brewDate << "', "
                          << "tapDate: '" << model.tapDate << "', "
                          << "fg: '" << model.fg << "'"
                          << "]";
        }
    };

    std::string temperature = "";
    TapViewModel leftTap;
    TapViewModel rightTap;
    bool buttonsVisible = false;

    bool operator==(const GuiViewModel& other) const
    {
        return
            temperature == other.temperature &&
            leftTap == other.leftTap &&
            rightTap == other.rightTap &&
            buttonsVisible == other.buttonsVisible;
    }

    friend std::ostream& operator<<(std::ostream& stream, const GuiViewModel& model)
    {
        return stream << "["
                      << "temperature: '" << model.temperature << "', "
                      << "leftTap: " << model.leftTap << ", "
                      << "rightTap: " << model.rightTap << ", "
                      << "buttonsVisible: '" << model.buttonsVisible << "'"
                      << "]";
    }
};

}

#endif
