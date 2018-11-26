#ifndef SRC_MAIN_PRESENTER_PRINTVIEWMODEL_H
#define SRC_MAIN_PRESENTER_PRINTVIEWMODEL_H

#include <string>

namespace KegeratorDisplay {

class PrintViewModel
{
public:
    PrintViewModel();
    virtual ~PrintViewModel();

    void setTemperature(const std::string& temperature);
    std::string getTemperature() const;

    void setLeftTapBeerInfo(const std::string& name);
    std::string getLeftTapBeerInfo() const;

    void setRightTapBeerInfo(const std::string& name);
    std::string getRightTapBeerInfo() const;

private:
    std::string m_temperature;
    std::string m_leftTapBeerInfo;
    std::string m_rightTapBeerInfo;
};

}

#endif
