#include "ScreenTouchedInteractorTest.h"
#include "interactors/ScreenTouchedInteractor.h"
#include "interactors/ScreenTouchedResponse.h"
#include "interactors/InvalidScreenTouchedInteractorArgumentException.h"
#include "unit/interactors/PresenterMock.h"
#include "unit/thread/DeadlineTimerMock.h"

using testing::_;
using testing::NiceMock;

namespace KegeratorDisplay {

ScreenTouchedInteractorTest::ScreenTouchedInteractorTest()
{
    m_timer = new NiceMock<DeadlineTimerMock>();
    m_presenter = new NiceMock<PresenterMock>();
    m_interactor= new ScreenTouchedInteractor(1, m_timer, *m_presenter);
}

ScreenTouchedInteractorTest::~ScreenTouchedInteractorTest()
{
    delete m_interactor;
    delete m_presenter;
}

TEST_F(ScreenTouchedInteractorTest, Create)
{
}

TEST_F(ScreenTouchedInteractorTest, HandleRequest)
{
    ScreenTouchedRequest request;
    m_interactor->handleRequest(request);
}

TEST_F(ScreenTouchedInteractorTest, SingleTapHandleRequestStartsTimer)
{
    EXPECT_CALL(*m_timer, asyncWaitSeconds(_, _))
        .Times(1);

    ScreenTouchedRequest request;
    m_interactor->handleRequest(request);
}

TEST_F(ScreenTouchedInteractorTest, DoubleTapHandleRequestCancelsTimer)
{
    ScreenTouchedRequest request;
    m_interactor->handleRequest(request);

    EXPECT_CALL(*m_timer, cancel())
        .Times(1);
    m_interactor->handleRequest(request);
}

TEST_F(ScreenTouchedInteractorTest, DoubleTapNotifiesPresenter)
{
    ScreenTouchedRequest request;
    m_interactor->handleRequest(request);
    ScreenTouchedResponse response(true);
    EXPECT_CALL(*m_presenter, screenTouched(response))
        .Times(1);
    m_interactor->handleRequest(request);
}

TEST_F(ScreenTouchedInteractorTest, SingleTapHandleRequestDoesNotCancelTimer)
{
    ScreenTouchedRequest request;
    EXPECT_CALL(*m_timer, cancel())
         .Times(0);
    m_interactor->handleRequest(request);
}

TEST_F(ScreenTouchedInteractorTest, ClickAfterTimeoutDoesNotNotify)
{
    ScreenTouchedRequest request;
    m_interactor->handleRequest(request);
    boost::system::error_code error;
    m_interactor->stuffHappened(error);

    EXPECT_CALL(*m_presenter, screenTouched(_))
        .Times(0);
    m_interactor->handleRequest(request);
}

}
