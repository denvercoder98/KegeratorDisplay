#ifndef SRC_MAIN_MONITOR_SPECIFICGRAVITY_H_
#define SRC_MAIN_MONITOR_SPECIFICGRAVITY_H_

#include <string>

namespace KegeratorDisplay {

class SpecificGravity {
public:
	SpecificGravity(const float gravity);
	virtual ~SpecificGravity();

	const std::string value() const;
	const bool operator==(const SpecificGravity& other) const;

private:
	void validateArgument(const float gravity);
	void setValue(const float gravity);

	std::string m_value;
};

}

#endif
