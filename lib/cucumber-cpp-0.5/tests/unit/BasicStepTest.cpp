#include <gtest/gtest.h>

#include <cucumber-cpp/internal/drivers/GenericDriver.hpp>

using namespace cucumber::internal;

#define PENDING_STEP_DESCRIPTION "A description"

class PendingStep : public GenericStep {
    void body() {
        pending();
    }
};

class PendingStepWithDescription : public GenericStep {
    void body() {
        pending(PENDING_STEP_DESCRIPTION);
    }
};

static const InvokeArgs NO_INVOKE_ARGS;

TEST(BasicStepTest, handlesPendingSteps) {
    PendingStep pendingStep;
    PendingStepWithDescription pendingStepWithDescription;
    InvokeResult result;

    result = pendingStep.invoke(&NO_INVOKE_ARGS);
    ASSERT_TRUE(result.isPending());
    ASSERT_STREQ("", result.getDescription().c_str());

    result = pendingStepWithDescription.invoke(&NO_INVOKE_ARGS);
    ASSERT_TRUE(result.isPending());
    ASSERT_STREQ(PENDING_STEP_DESCRIPTION, result.getDescription().c_str());
}
