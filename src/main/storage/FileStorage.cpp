#include <storage/FileStorage.h>
#include "storage/FileWriter.h"
#include "storage/FileReader.h"
#include "monitor/Tap.h"
#include "monitor/Temperature.h"

#include <sstream>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/split_member.hpp>

namespace KegeratorDisplay {

FileStorage::FileStorage(const std::string& temperatureFilename,
                         const std::string& leftTapFilename,
                         const std::string& rightTapFilename,
                         FileWriter* writer,
                         FileReader* reader) :
    m_temperatureFilename(temperatureFilename),
    m_leftTapFilename(leftTapFilename),
    m_rightTapFilename(rightTapFilename),
    m_reader(reader),
    m_writer(writer)
{
}

FileStorage::~FileStorage()
{
    delete m_writer;
    delete m_reader;
}

Temperature* FileStorage::readTemperature()
{
    std::string serialized = m_reader->read(m_temperatureFilename);
    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Temperature *t = new Temperature();
    ia >> *t;
    return t;
}

void FileStorage::writeTemperature(Temperature* temperature)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *temperature;
    const std::string serialized = ss.str();
    m_writer->truncateAndWrite(m_temperatureFilename, serialized);
}

Tap* FileStorage::readLeftTap()
{
    std::string serialized = m_reader->read(m_leftTapFilename);
    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Tap *t = new Tap();
    ia >> *t;
    return t;
}

void FileStorage::writeLeftTap(Tap* tap)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *tap;
    const std::string serialized = ss.str();
    m_writer->truncateAndWrite(m_leftTapFilename, serialized);
}

Tap* FileStorage::readRightTap()
{
    std::string serialized = m_reader->read(m_rightTapFilename);
    std::istringstream ss(serialized);
    boost::archive::text_iarchive ia(ss);
    Tap *t = new Tap();
    ia >> *t;
    return t;
}

void FileStorage::writeRightTap(Tap* tap)
{
    std::ostringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << *tap;
    const std::string serialized = ss.str();
    m_writer->truncateAndWrite(m_rightTapFilename, serialized);
}

}

BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::Temperature)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::Tap)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::Beer)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::AlcoholByVolume)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::InternationalBitternessUnits)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::Date)
BOOST_SERIALIZATION_SPLIT_FREE(KegeratorDisplay::SpecificGravity)

namespace boost {
namespace serialization {

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::Temperature& t, const unsigned int version)
{
    std::vector<int> readings = t.getReadings();
    ar & readings;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::Temperature& t, const unsigned int version)
{
    std::vector<int> readings;
    ar & readings;
    t.setReadings(readings);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::Tap& t, const unsigned int version)
{
    KegeratorDisplay::Beer beer = t.beer();
    ar & beer;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::Tap& t, const unsigned int version)
{
    KegeratorDisplay::Beer beer;
    ar & beer;
    t.setBeer(beer);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::AlcoholByVolume& abv, const unsigned int version)
{
    const std::string value = abv.value();
    ar & value;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::AlcoholByVolume& abv, const unsigned int version)
{
    std::string value;
    ar & value;
    double temp = ::atof(value.c_str());
    abv.setAbv(temp);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::InternationalBitternessUnits& ibu, const unsigned int version)
{
    const unsigned int value = ibu.value();
    ar & value;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::InternationalBitternessUnits& ibu, const unsigned int version)
{
    unsigned int value;
    ar & value;
    ibu.setIbu(value);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::Date& date, const unsigned int version)
{
    const unsigned int year = date.year();
    const unsigned int month = date.month();
    const unsigned int day = date.day();
    ar & year;
    ar & month;
    ar & day;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::Date& date, const unsigned int version)
{
    unsigned int year;
    unsigned int month;
    unsigned int day;

    ar & year;
    ar & month;
    ar & day;

    date.setDate(year, month, day);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::SpecificGravity& sg, const unsigned int version)
{
    const std::string value = sg.value();
    ar & value;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::SpecificGravity& sg, const unsigned int version)
{
    std::string value;
    ar & value;
    double temp = ::atof(value.c_str());
    sg.setSG(temp);
}

template<class Archive>
void save(Archive & ar, const KegeratorDisplay::Beer& b, const unsigned int version)
{
    const std::string name = b.name();
    ar & name;

    const std::string brewerName = b.brewerName();
    ar & brewerName;

    const KegeratorDisplay::AlcoholByVolume abv = b.alcoholByVolume();
    ar & abv;

    const KegeratorDisplay::InternationalBitternessUnits ibu = b.internationalBitternessUnits();
    ar & ibu;

    const KegeratorDisplay::Date brewDate = b.brewDate();
    ar & brewDate;

    const KegeratorDisplay::Date tapDate = b.tapDate();
    ar & tapDate;

    const KegeratorDisplay::SpecificGravity finalGravity = b.finalGravity();
    ar & finalGravity;
}

template<class Archive>
void load(Archive & ar, KegeratorDisplay::Beer& b, const unsigned int version)
{
    std::string name;
    ar & name;
    b.setName(name);

    std::string brewerName;
    ar & brewerName;
    b.setBrewerName(brewerName);

    KegeratorDisplay::AlcoholByVolume abv;
    ar & abv;
    b.setAlcoholByVolume(abv);

    KegeratorDisplay::InternationalBitternessUnits ibu;
    ar & ibu;
    b.setInternationalBitternessUnits(ibu);

    KegeratorDisplay::Date brewDate;
    ar & brewDate;
    b.setBrewDate(brewDate);

    KegeratorDisplay::Date tapDate;
    ar & tapDate;
    b.setTapDate(tapDate);

    KegeratorDisplay::SpecificGravity finalGravity;
    ar & finalGravity;
    b.setFinalGravity(finalGravity);
}

} // namespace serialization
} // namespace boost
