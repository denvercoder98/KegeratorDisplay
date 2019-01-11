#include <devices/SpiReaderStaticValue.h>
#include <cstring>

namespace KegeratorDisplay {

SpiReaderStaticValue::SpiReaderStaticValue()
{
}

SpiReaderStaticValue::~SpiReaderStaticValue()
{
}

void SpiReaderStaticValue::read(unsigned char* buffer, unsigned int bufferLength)
{
    const unsigned char staticValue[4] = "512";
    //TODO buffer overflow
    memcpy(buffer, staticValue, 4);
}

}
