#ifndef SRC_MAIN_CLIVIEW_CLIVIEW_H_
#define SRC_MAIN_CLIVIEW_CLIVIEW_H_

#include "presenter/PrintView.h"
#include "View.h"

namespace KegeratorDisplay {

class CliView: public PrintView, public View {
public:
	CliView();
	virtual ~CliView();

	void updateView(const PrintViewModel& viewModel);
	void run(int argc, char** argv) {};
};

}

#endif /* SRC_MAIN_CLIVIEW_CLIVIEW_H_ */
