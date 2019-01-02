#ifndef SRC_MAIN_PRESENTER_TAPVIEWMODEL_H_
#define SRC_MAIN_PRESENTER_TAPVIEWMODEL_H_

#include <string>
#include <ostream>

namespace KegeratorDisplay {

class TapViewModel
{
public:
    class Tap
    {
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

        bool operator==(const Tap& other) const
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

        friend std::ostream& operator<<(std::ostream& stream, const Tap& model)
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

    Tap leftTap;
    Tap rightTap;

    friend std::ostream& operator<<(std::ostream& stream, const TapViewModel& model)
    {
        return stream << "["
                      << "leftTap: " << model.leftTap << ", "
                      << "rightTap: " << model.rightTap
                      << "]";
    }

    bool operator==(const TapViewModel& other) const
    {
        return leftTap == other.leftTap &&
            rightTap == other.rightTap;
    }
};

}

#endif
