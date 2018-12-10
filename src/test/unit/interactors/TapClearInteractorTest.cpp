#include "TapClearInteractorTest.h"
#include "PresenterMock.h"
#include "StorageMock.h"
#include "interactors/TapClearInteractor.h"

using testing::NiceMock;

namespace KegeratorDisplay {

TapClearInteractorTest::TapClearInteractorTest() :
    m_presenter(NULL),
    m_storage(NULL),
    m_interactor(NULL)
{
}

TapClearInteractorTest::~TapClearInteractorTest()
{
}

void TapClearInteractorTest::SetUp()
{
    m_presenter = new NiceMock<PresenterMock>();
    m_storage = new NiceMock<StorageMock>();
    m_interactor = new TapClearInteractor(m_presenter, *m_storage);
}

void TapClearInteractorTest::TearDown()
{
    delete m_interactor;
    delete m_storage;
    delete m_presenter;
}

TEST_F(TapClearInteractorTest, Create)
{
}

TEST_F(TapClearInteractorTest, HandleRequestClearLeftClearsStorage)
{
    EXPECT_CALL(*m_storage, clearLeftTap())
        .Times(1);

    TapClearRequest request(TAP_LEFT);
    m_interactor->handleRequest(request);
}

TEST_F(TapClearInteractorTest, HandleRequestClearLeftUpdatesPresenter)
{
    TapClearResponse expectedResponse(TAP_LEFT);
    EXPECT_CALL(*m_presenter, clearTap(expectedResponse))
        .Times(1);

    TapClearRequest request(TAP_LEFT);
    m_interactor->handleRequest(request);
}

TEST_F(TapClearInteractorTest, HandleRequestClearRightClearsStorage)
{
    EXPECT_CALL(*m_storage, clearRightTap())
        .Times(1);

    TapClearRequest request(TAP_RIGHT);
    m_interactor->handleRequest(request);
}

TEST_F(TapClearInteractorTest, HandleRequestClearRightUpdatesPresenter)
{
    TapClearResponse expectedResponse(TAP_RIGHT);
    EXPECT_CALL(*m_presenter, clearTap(expectedResponse))
        .Times(1);

    TapClearRequest request(TAP_RIGHT);
    m_interactor->handleRequest(request);
}

}
