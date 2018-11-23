#ifndef SRC_MAIN_CLIVIEW_CLIVIEW_H_
#define SRC_MAIN_CLIVIEW_CLIVIEW_H_

#include "presenter/PrintView.h"

namespace KegeratorDisplay {

class CliView: public PrintView {
public:
	CliView();
	virtual ~CliView();

	virtual void updateView(const PrintViewModel& viewModel);
};

}

#endif /* SRC_MAIN_CLIVIEW_CLIVIEW_H_ */
