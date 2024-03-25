#include "TestSchedule.h"

void TestSchedule::addStep(TestStep testStep) {
    schedule.push_back(testStep);
}

TestStep TestSchedule::nextStep() {
    if (currentStepIndex < schedule.size()) {
        TestStep nextTestStep = schedule[currentStepIndex];
        currentStepIndex++;
        return nextTestStep;
    }
    else {
        return { CONSTANT_VOLTAGE, 0.0, 0.0 };
    }
}

bool TestSchedule::hasNextStep() {
    return currentStepIndex < schedule.size();
}