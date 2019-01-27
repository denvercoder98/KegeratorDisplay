#include <controllers/DeviceTapData.h>

namespace KegeratorDisplay {

DeviceTapData::DeviceTapData(const std::string& name,
              const std::string& estVolume,
              const std::string& brewer,
              const std::string& abv,
              const std::string& ibu,
              const std::string& brewDate,
              const std::string& tapDate,
              const std::string& finalGravity) :
                  name(name),
                  estVolume(estVolume),
                  brewer(brewer),
                  abv(abv),
                  ibu(ibu),
                  brewDate(brewDate),
                  tapDate(tapDate),
                  finalGravity(finalGravity)
{
}

DeviceTapData::~DeviceTapData()
{
}

bool DeviceTapData::operator==(const DeviceTapData& other) const
{
    return name == other.name &&
        estVolume == other.estVolume &&
        brewer == other.brewer &&
        abv == other.abv &&
        ibu == other.ibu &&
        brewDate == other.brewDate &&
        tapDate == other.tapDate &&
        finalGravity == other.finalGravity;
}

bool DeviceTapData::operator!=(const DeviceTapData& other) const
{
    return !(*this == other);
}

}
