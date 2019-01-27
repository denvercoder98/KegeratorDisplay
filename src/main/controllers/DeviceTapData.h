#ifndef SRC_MAIN_CONTROLLERS_DEVICETAPDATA_H_
#define SRC_MAIN_CONTROLLERS_DEVICETAPDATA_H_

#include <string>
#include <ostream>

namespace KegeratorDisplay {

class DeviceTapData
{
public:
    DeviceTapData(const std::string& name,
                  const std::string& estVolume,
                  const std::string& brewer,
                  const std::string& abv,
                  const std::string& ibu,
                  const std::string& brewDate,
                  const std::string& tapDate,
                  const std::string& finalGravity);
    virtual ~DeviceTapData();

    bool operator==(const DeviceTapData& other) const;
    bool operator!=(const DeviceTapData& other) const;

    friend std::ostream& operator<<(std::ostream& stream, DeviceTapData const& data)
    {
        return stream << "["
                      << "name: '" << data.name << "', "
                      << "estVolume: '" << data.estVolume << "', "
                      << "brewer: '" << data.brewer << "', "
                      << "abv: '" << data.abv << "', "
                      << "ibu: '" << data.ibu << "', "
                      << "brewDate: '" << data.brewDate << "', "
                      << "tapDate: '" << data.tapDate << "', "
                      << "finalGravity: '" << data.finalGravity << "'"
                      << "]";
    }

    const std::string name;
    const std::string estVolume;
    const std::string brewer;
    const std::string abv;
    const std::string ibu;
    const std::string brewDate;
    const std::string tapDate;
    const std::string finalGravity;
};

}

#endif
