#ifndef SRC_TEST_PRESENTER_PRINTVIEWMOCK_H
#define SRC_TEST_PRESENTER_PRINTVIEWMOCK_H

#include "src/main/presenter/PrintView.h"
#include "gmock/gmock.h"

class PrintViewMock : public PrintView
{
public:
	MOCK_METHOD1(updateView, void(const PrintViewModel& viewModel));
};

#endif
