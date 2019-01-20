#include "SpiReaderStaticValue.h"
#include <cstring>

namespace KegeratorDisplay {

SpiReaderStaticValue::SpiReaderStaticValue() :
    m_cnt(0)
{
}

SpiReaderStaticValue::~SpiReaderStaticValue()
{
}

void SpiReaderStaticValue::read(unsigned char* buffer, unsigned int bufferLength)
{
    const unsigned char staticValue[4] = "210";
    const unsigned char staticValue2[4] = "220";

    if (m_cnt < 4) {
        //TODO buffer overflow
        memcpy(buffer, staticValue, 4);
    }
    else {
        //TODO buffer overflow
        memcpy(buffer, staticValue2, 4);
    }

    m_cnt = (++m_cnt)%8;
}

}
