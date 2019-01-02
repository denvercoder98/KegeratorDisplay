#ifndef SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_GUIVIEWMODEL_H_

#include <string>
#include <ostream>

namespace KegeratorDisplay {

class GuiViewModel
{
public:
    std::string heading = "Kegerator Status";
    std::string pressureTag = "Pressure: ";
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
    std::string saveButtonTag = "Save";

    bool operator==(const GuiViewModel& other) const
    {
        return
            heading == other.heading &&
            pressureTag == other.pressureTag &&
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
                      << "buttonsVisible: '" << model.buttonsVisible << "'"
                      << "]";
    }
};

}

#endif
