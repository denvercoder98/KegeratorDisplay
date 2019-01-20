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

TEST_F(PressureUpdateInteractorTest, UpdateResponseOnUpdateRequestTranslatesToPressure100PsiMax)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);

    EXPECT_CALL(presenter, updatePressure(PressureUpdateResponse(Bar(6.9))))
        .Times(1);
    AdcReading10Bit value(930);
    interactor.updateValue(value);
}

TEST_F(PressureUpdateInteractorTest, UpdateResponseOnUpdateRequestTranslatesToPressure100PsiMin)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);

    EXPECT_CALL(presenter, updatePressure(PressureUpdateResponse(Bar(0))))
        .Times(1);
    AdcReading10Bit value(102);
    interactor.updateValue(value);
}

TEST_F(PressureUpdateInteractorTest, UpdateResponseOnUpdateRequestTranslatesToPressure100Psi50Psi)
{
    NiceMock<PresenterMock> presenter;
    PressureUpdateInteractor interactor(presenter);

    EXPECT_CALL(presenter, updatePressure(PressureUpdateResponse(Bar(3.5))))
        .Times(1);
    AdcReading10Bit value(527);
    interactor.updateValue(value);
}


}
