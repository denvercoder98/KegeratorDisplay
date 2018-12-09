#ifndef SRC_MAIN_INTERACTORS_SCREENTOUCHEDREQUEST_H_
#define SRC_MAIN_INTERACTORS_SCREENTOUCHEDREQUEST_H_

namespace KegeratorDisplay {

class ScreenTouchedRequest
{
public:
    ScreenTouchedRequest();
    virtual ~ScreenTouchedRequest();

    bool operator==(const ScreenTouchedRequest& other) const;
};

}

#endif
