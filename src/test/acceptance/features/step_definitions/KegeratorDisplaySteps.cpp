#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <iostream>
#include <Kegerator.h>

using cucumber::ScenarioScope;
using namespace KegeratorDisplay;

class Calculator {
public:
	Calculator() {};
	
	void push(double n) {
		std::cout << "PUSH" << std::endl;
	};

	int add() {
		std::cout << "ADD" << std::endl;
		return 3;
	};
};

struct CalcCtx {
    Calculator calc;
    //Kegerator kegerator;
    double result;
};

GIVEN("Application started") {
    ScenarioScope<CalcCtx> context;

    //context->kegerator.start();
}

GIVEN("Beer on left tap") {
}

GIVEN("Beer on right tap") {
}

GIVEN("^I have entered (\\d+) into the calculator$") {
    REGEX_PARAM(double, n);
    ScenarioScope<CalcCtx> context;

    context->calc.push(n);
}

WHEN("^I press add") {
    ScenarioScope<CalcCtx> context;

    context->result = context->calc.add();
}

THEN("^the result should be (.*) on the screen$") {
    REGEX_PARAM(double, expected);
    ScenarioScope<CalcCtx> context;

    EXPECT_EQ(expected, context->result);
}
