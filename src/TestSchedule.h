#ifndef TESTSCHEDULE_H
#define TESTSCHEDULE_H
#include <vector>

enum ControlType {
    CONSTANT_VOLTAGE,
    CONSTANT_CURRENT,
    CCCV
};
struct TestStep {
    ControlType controlType;
    double value;
    double duration;

    TestStep(ControlType controlType, double value, double duration)
        : controlType(controlType), value(value), duration(duration) {}
};

class TestSchedule
{
public:
    void addStep(TestStep testStep);
    TestStep nextStep();
    bool hasNextStep();
    void displayTestSchedule();

private:
    std::vector<TestStep> schedule;
    size_t currentStepIndex = 0;
};

#endif