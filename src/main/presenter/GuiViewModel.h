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
        std::string side = "";
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
                side == other.side &&
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
                          << "side: " << model.side << ", "
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

    std::string heading = "Kegerator Status";
    std::string temperatureTag = "Temperature: ";
    std::string temperature = "";
    std::string pressureTag = "Pressure: ";
    TapViewModel leftTap;
    TapViewModel rightTap;
    bool buttonsVisible = false;

    std::string beerNameTag = "Name: ";
    std::string brewerNameTag = "Brewer Name: ";
    std::string estVolumeTag = "Est. Volume: ";
    std::string abvTag = "ABV: ";
    std::string ibuTag = "IBU: ";
    std::string brewDateTag = "Brew Date: ";
    std::string tapDateTag = "Tap Date: ";
    std::string fgTag = "FG: ";

    std::string clearButtonTag = "Clear";

    bool operator==(const GuiViewModel& other) const
    {
        return
            heading == other.heading &&
            temperature == other.temperature &&
            temperatureTag == other.temperatureTag &&
            pressureTag == other.pressureTag &&
            leftTap == other.leftTap &&
            rightTap == other.rightTap &&
            buttonsVisible == other.buttonsVisible &&
            beerNameTag == other.beerNameTag &&
            brewerNameTag == other.brewerNameTag &&
            abvTag == other.abvTag &&
            ibuTag == other.ibuTag &&
            brewDateTag == other.brewDateTag &&
            tapDateTag == other.tapDateTag &&
            fgTag == other.fgTag &&
            clearButtonTag == other.clearButtonTag;
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
