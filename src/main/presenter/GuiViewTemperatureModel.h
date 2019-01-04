#ifndef SRC_MAIN_PRESENTER_GUIVIEWTEMPERATUREMODEL_H_
#define SRC_MAIN_PRESENTER_GUIVIEWTEMPERATUREMODEL_H_

#include <string>
#include <ostream>

namespace KegeratorDisplay {

class GuiViewTemperatureModel
{
public:
    std::string temperatureTag = "Temperature: ";
    std::string temperature = "";
    std::string temperatureUnit = "";

    bool operator==(const GuiViewTemperatureModel& other) const
    {
        return
            temperature == other.temperature &&
            temperatureTag == other.temperatureTag &&
            temperatureUnit == other.temperatureUnit;
    }

    friend std::ostream& operator<<(std::ostream& stream, const GuiViewTemperatureModel& model)
    {
        return stream << "["
                      << "temperature: '" << model.temperature << "', "
                      << "temperatureTag: '" << model.temperatureTag << "', "
                      << "temperatureUnit: '" << model.temperatureUnit << "'"
                      << "]";
    }
};

}

#endif
