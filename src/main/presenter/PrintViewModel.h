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

private:
    std::string m_temperature;
};

}

#endif
