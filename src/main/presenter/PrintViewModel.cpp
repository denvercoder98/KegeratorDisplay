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

void PrintViewModel::setLeftTapBeerInfo(const std::string& info)
{
    m_leftTapBeerInfo = info;
}

std::string PrintViewModel::getLeftTapBeerInfo() const
{
    return m_leftTapBeerInfo;
}

void PrintViewModel::setRightTapBeerInfo(const std::string& info)
{
    m_rightTapBeerInfo = info;
}

std::string PrintViewModel::getRightTapBeerInfo() const
{
    return m_rightTapBeerInfo;
}

}
