#ifndef SRC_MAIN_CLIVIEW_CLIVIEW_H_
#define SRC_MAIN_CLIVIEW_CLIVIEW_H_

#include "src/main/presenter/PrintView.h"

class CliView: public PrintView {
public:
	CliView();
	virtual ~CliView();

	virtual void updateView(const PrintViewModel& viewModel);
};

#endif /* SRC_MAIN_CLIVIEW_CLIVIEW_H_ */
