#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <cucumber-cpp/internal/ContextManager.hpp>
#include <iostream>
//#include "acceptance/AcceptanceTestKegerator.h"
#include <boost/asio/io_service.hpp>

using cucumber::ScenarioScope;
//using namespace KegeratorDisplay;

class Calculator {
public:
    Calculator() :
        result(3),
        m_ioService(),
        m_work(m_ioService) {};

    double add() {
        return result;
    }

    double divide() {
        return result;
    }

    void push(double a) {
        result = 10;
    }

private:
    double result;
    boost::asio::io_service m_ioService;
    boost::asio::io_service::work m_work;
};

struct CalcCtx {
    //AcceptanceTestKegerator kegerator;
    Calculator calc;
    double result;
};

GIVEN("^I have entered (\\d+) into the calculator$") {
    REGEX_PARAM(double, n);
    ScenarioScope<CalcCtx> context;

    context->calc.push(n);
}

WHEN("^I press add") {
    ScenarioScope<CalcCtx> context;

    context->result = context->calc.add();
}

WHEN("^I press divide") {
    ScenarioScope<CalcCtx> context;

    context->result = context->calc.divide();
}

THEN("^the result should be (.*) on the screen$") {
    REGEX_PARAM(double, expected);
    ScenarioScope<CalcCtx> context;

    EXPECT_EQ(expected, context->result);
}
