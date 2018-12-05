#ifndef SRC_TEST_ACCEPTANCE_ACCEPTANCETESTKEGERATOR_H_
#define SRC_TEST_ACCEPTANCE_ACCEPTANCETESTKEGERATOR_H_

#include "Kegerator.h"
#include "presenter/GuiView.h"

namespace KegeratorDisplay {

class AcceptanceTestInputDevice;
class AcceptanceTestGuiView;

class AcceptanceTestKegerator : public Kegerator, public GuiView
{
public:
    AcceptanceTestKegerator();
    virtual ~AcceptanceTestKegerator();

    void updateView(const GuiViewModel& view);

    GuiViewModel getViewModel() const;
    void clearLeftTap();

protected:
    void createView(int &argc, char** argv);
    void createDevices();
    void run();

private:
    AcceptanceTestGuiView* m_view;
    AcceptanceTestInputDevice* m_inputDevice;
    GuiViewModel m_currentViewModel;
};

}

#endif
