#include <gtest/gtest.h>

#include <cucumber-cpp/internal/step/StepMacros.hpp>
#include "../utils/CukeCommandsFixture.hpp"

#include <boost/config.hpp>

using namespace cucumber::internal;

using std::string;

class CukeCommandsTest : public CukeCommandsFixture {
protected:
    void addStepWithMatcher(const std::string &matcher) {
        addStepToManager<EmptyStep>(matcher);
    }
};

class CheckAllParameters : public GenericStep {
protected:
    static const int arg_0_int;
    static const double arg_1_double;
    static const string arg_2_string;
    static const string arg_3_string_with_spaces;

public:
    static InvokeArgs buildInvokeArgs() {
        InvokeArgs mixedArgs;
        mixedArgs.addArg(toString(arg_0_int));
        mixedArgs.addArg(toString(arg_1_double));
        mixedArgs.addArg(toString(arg_2_string));
        mixedArgs.addArg(toString(arg_3_string_with_spaces));
        return mixedArgs;
    }
};

const int CheckAllParameters::arg_0_int(42);
const double CheckAllParameters::arg_1_double(4.2);
const string CheckAllParameters::arg_2_string("fortytwo");
const string CheckAllParameters::arg_3_string_with_spaces("forty two");

class CheckAllParametersWithoutMacro : public CheckAllParameters {
public:
    void body() {
        EXPECT_EQ(arg_0_int, getArgs()->getInvokeArg<int>(0));
        EXPECT_EQ((double)arg_0_int, getArgs()->getInvokeArg<double>(0));
        EXPECT_NO_THROW(getArgs()->getInvokeArg<string>(0));

        EXPECT_EQ((int)arg_1_double, getArgs()->getInvokeArg<int>(1));
        EXPECT_EQ(arg_1_double, getArgs()->getInvokeArg<double>(1));
        EXPECT_NO_THROW(getArgs()->getInvokeArg<string>(1));

        EXPECT_THROW(getArgs()->getInvokeArg<int>(2), std::invalid_argument);
        EXPECT_THROW(getArgs()->getInvokeArg<double>(2), std::invalid_argument);
        EXPECT_EQ(arg_2_string, getArgs()->getInvokeArg<string>(2));

        EXPECT_THROW(getArgs()->getInvokeArg<int>(3), std::invalid_argument);
        EXPECT_THROW(getArgs()->getInvokeArg<double>(3), std::invalid_argument);
        EXPECT_EQ(arg_3_string_with_spaces, getArgs()->getInvokeArg<string>(3));
    }
};

class CheckAllParametersWithMacro : public CheckAllParameters {
public:
    void body() {
        REGEX_PARAM(int, got_arg_0_int);
        EXPECT_EQ(arg_0_int, got_arg_0_int);

        REGEX_PARAM(double, got_arg_1_double);
        EXPECT_EQ(arg_1_double, got_arg_1_double);

        REGEX_PARAM(string, got_arg_2_string);
        EXPECT_EQ(arg_2_string, got_arg_2_string);

        REGEX_PARAM(string, got_arg_3_string_with_spaces);
        EXPECT_EQ(arg_3_string_with_spaces, got_arg_3_string_with_spaces);
    }
};

#ifndef BOOST_NO_VARIADIC_TEMPLATES
class CheckAllParametersWithFuncArgs : public CheckAllParameters {
public:
    void bodyWithArgs(
            const int          got_arg_0_int
          , const double       got_arg_1_double
          , const std::string  got_arg_2_string
          , const std::string& got_arg_3_string_with_spaces
          ) {
        EXPECT_EQ(arg_0_int, got_arg_0_int);
        EXPECT_EQ(arg_1_double, got_arg_1_double);
        EXPECT_EQ(arg_2_string, got_arg_2_string);
        EXPECT_EQ(arg_3_string_with_spaces, got_arg_3_string_with_spaces);
    }

    void body() {
        return invokeWithArgs(*this, &CheckAllParametersWithFuncArgs::bodyWithArgs);
    }
};

TEST_F(CukeCommandsTest, invokeHandlesParametersWithFuncArgs) {
    // The real test is in TestClass::body()
    runStepBodyTest<CheckAllParametersWithFuncArgs>();
}
#endif

TEST_F(CukeCommandsTest, matchesCorrectly) {
    addStepWithMatcher(STATIC_MATCHER);
    MatchResult result = stepMatches(STATIC_MATCHER);
    EXPECT_EQ(stepId, result.getResultSet().at(0).stepInfo->id);
}

TEST_F(CukeCommandsTest, invokeHandlesParametersWithoutMacro) {
    // The real test is in TestClass::body()
    runStepBodyTest<CheckAllParametersWithoutMacro>();
}

TEST_F(CukeCommandsTest, invokeHandlesParametersWithMacro) {
    // The real test is in TestClass::body()
    runStepBodyTest<CheckAllParametersWithMacro>();
}

TEST_F(CukeCommandsTest, producesSnippetsEscapingTitle) {
    EXPECT_EQ("THEN(\"^x\\\\|y\\\"z$\") {\n"
              "    pending();\n"
              "}\n",
              snippetText("then","x|y\"z"));
}

TEST_F(CukeCommandsTest, escapesCaractersInRegexes) {
    //  abc|()[]{}^$*+?.\def  <=  abc\|\(\)\[\]\{\}\^\$\*\+\?\.\\def
    EXPECT_EQ("abc\\|\\(\\)\\[\\]\\{\\}\\^\\$\\*\\+\\?\\.\\\\def", escapeRegex("abc|()[]{}^$*+?.\\def"));
}

TEST_F(CukeCommandsTest, escapesCharactersInCStrings) {
    //  abc\"def\\ghi  <=  abc"def\ghi
    EXPECT_EQ("abc\\\"def\\\\ghi", escapeCString("abc\"def\\ghi"));
}
