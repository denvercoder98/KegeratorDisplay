#ifndef SRC_MAIN_ENTITIES_SPECIFICGRAVITY_H_
#define SRC_MAIN_ENTITIES_SPECIFICGRAVITY_H_

#include <string>

namespace KegeratorDisplay {

class SpecificGravity {
public:
    SpecificGravity();
	SpecificGravity(const float gravity);
	virtual ~SpecificGravity();

	const std::string value() const;
	const bool operator==(const SpecificGravity& other) const;

	void setSG(const float gravity);

private:
	void validateArgument(const float gravity);
	void setValue(const float gravity);

	std::string m_value;
};

}

#endif
