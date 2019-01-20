#ifndef SRC_MAIN_DEVICES_SPIREADERSTATICVALUE_H_
#define SRC_MAIN_DEVICES_SPIREADERSTATICVALUE_H_

#include "SpiReader.h"

namespace KegeratorDisplay {

class SpiReaderStaticValue : public SpiReader
{
public:
    SpiReaderStaticValue();
    virtual ~SpiReaderStaticValue();

    void initialize() {};
    void read(unsigned char* buffer, unsigned int bufferLength);

private:
    int m_cnt;
};

}

#endif
