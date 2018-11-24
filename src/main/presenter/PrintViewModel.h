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
    void setLeftTap(const std::string& tap);
    void setRightTap(const std::string& tap);

    void setLeftTapName(const std::string& name);
    void setLeftTapBrewerName(const std::string& brewerName);
    void setRightTapName(const std::string& name);
    void setRightTapBrewerName(const std::string& brewerName);

private:
    std::string m_temperature;
    std::string m_leftTapName;
    std::string m_leftTapBrewerName;
    std::string m_rightTapName;
    std::string m_rightTapBrewerName;
};

}

#endif
