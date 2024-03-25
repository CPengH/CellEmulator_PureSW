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
};

class TestSchedule
{
public:
    void addStep(TestStep testStep);
    TestStep nextStep();
    bool hasNextStep();

private:
    std::vector<TestStep> schedule;
    size_t currentStepIndex;
};