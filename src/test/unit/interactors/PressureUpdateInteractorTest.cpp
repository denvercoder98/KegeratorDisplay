#include "PressureUpdateInteractorTest.h"
#include "interactors/PressureUpdateInteractor.h"
#include "interactors/AnalogDigitalConverterUpdateRequestObserver.h"
#include "PresenterMock.h"

using testing::NiceMock;
using testing::_;

namespace KegeratorDisplay {

PressureUpdateInteractorTest::PressureUpdateInteractorTest()
{
}

PressureUpdateInteractorTest::~PressureUpdateInteractorTest()
{
}

TEST_F(PressureUpdateInteractorTest, Create)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);
}

TEST_F(PressureUpdateInteractorTest, IsObservingAnalogiDigitalConverterUpdateRequest)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);
    AnalogDigitalConverterUpdateRequestObserver* observer = dynamic_cast<AnalogDigitalConverterUpdateRequestObserver*>(&interactor);
    EXPECT_TRUE(observer != NULL);
}

TEST_F(PressureUpdateInteractorTest, UpdateResponseOnUpdateRequest)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);

    EXPECT_CALL(presenter, updatePressure(_))
        .Times(1);
    AdcReading10Bit value(42);
    interactor.updateValue(value);
}

TEST_F(PressureUpdateInteractorTest, UpdateResponseOnUpdateRequestValue)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);

    EXPECT_CALL(presenter, updatePressure(PressureUpdateResponse(RelativePressureBar(1))))
        .Times(1);
    AdcReading10Bit value(42);
    interactor.updateValue(value);
}

}
