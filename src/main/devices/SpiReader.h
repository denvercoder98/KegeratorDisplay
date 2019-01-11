#ifndef SRC_MAIN_DEVICES_SPIREADER_H_
#define SRC_MAIN_DEVICES_SPIREADER_H_

namespace KegeratorDisplay {

class SpiReader
{
public:
    virtual ~SpiReader() {};

    virtual void initialize() = 0;
    virtual void read(unsigned char* buffer, unsigned int length) = 0;
};

}

#endif
