#include "PrintViewModel.h"

namespace KegeratorDisplay {

PrintViewModel::PrintViewModel() :
    m_temperature("")
{
}

PrintViewModel::~PrintViewModel()
{
}

void PrintViewModel::setTemperature(const std::string& temperature)
{
    m_temperature = temperature;
}

std::string PrintViewModel::getTemperature() const
{
    return m_temperature;
}

void PrintViewModel::setLeftTapName(const std::string& name)
{
    m_leftTapName = name;
}

void PrintViewModel::setLeftTapBrewerName(const std::string& brewerName)
{
    m_leftTapBrewerName = brewerName;
}

void PrintViewModel::setRightTapName(const std::string& name)
{
    m_rightTapName = name;
}

void PrintViewModel::setRightTapBrewerName(const std::string& brewerName)
{
    m_rightTapBrewerName = brewerName;
}

}
