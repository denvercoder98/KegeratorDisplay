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

}
