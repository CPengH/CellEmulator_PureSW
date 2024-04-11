# Cell Emulator

## Description

This is a project designed to simulate battery cell behavior, which might be a time-consuming and high-cost task in research. The project can serve as the first phase in research to obtain the POC (Proof of Concept) before actually starting the battery experiment. It doesn't mean the actual experiment is unnecessary; it just helps you to verify that the results align with your expectations.

## Build

This is a cross-platform project that uses CMake, and there are scripts available for compilation as well.
- On Windows, use `build.bat`
- On macOS/Linux, use `sh build.sh`

## Demo

The demo attempts to simulate an 18650 battery cell with a capacity of 3500mAh and charges it from 0% to 100% using a constant current of 3.5A (equivalent to 1C).

It will automatically generate a csv log file to document the charging process.
<p align="center">
<img src="readme_preview/OCV_SOC_demo.png" width=500>
</p>

## Cutomize

There are two aspects you can customize in the current version:

1. Input a different benchmark spreadsheet for various battery cells. (Place the file in the inputExcel folder and execute the program with its path.)
   ```
   $ cellEmulator.exe <path_to_spreadsheet_csv>
   ```
2. Customize the test schedule with various currents and time durations. (Future versions will support additional control types, such as constant voltage or CCCV.)
```
int main()
{
    std::string filePath;

    if (argc == 1) {
        filePath = "../../inputExcel/DefaultSpreadSheet.csv";
    } else if (argc == 2) {
        filePath = argv[0];
    } else {
        printHelp();
        return 0;
    }

    // Step0. Load the spreadsheet
    std::vector<std::pair<double, double>> socToOcvPairs = ExcelReader::readSocToOcvMap(filePath);

    // Step1. Input the benchmark spreadsheet for the cell
    BatteryModel testModel(0, socToOcvPairs, 3500);
    testModel.displayBatteryParams();

    // Step2. Customize the test schedule
    TestSchedule schedule;
    schedule.addStep(TestStep(CONSTANT_CURRENT, 3.5, 3600));
    
    // Step3. Run the simulation
    SimulationEngine simEng(testModel, schedule);
    simEng.runSimulation();
    
    testModel.displayBatteryParams();
    system("pause");
    return 0;
}
```

## Planned Features

Here are some of the features I plan to implement in the future and tasks:

- [X] Input via Excel files for a broader range of spreadsheet formats.
- [ ] Enhanced control types for testing, including constant voltage and CCCV (Constant Current Constant Voltage).
- [ ] Implement a more intuitive user interface for easy setup and monitoring of simulations.

Please note that these features are subject to change and may evolve based on project needs and contributions.

## Contributing

Welcome contributions from everyone! If you're interested in helping improve this project, please feel free to fork the repository, make your changes, and submit a pull request. Your contributions are greatly appreciated and will help make this project better for everyone.

If you are an electrochemist and wish to provide optimizations for the simulation engine but are unsure about implementing your ideas in code, you are welcome to add a plain text file to illustrate your ideas. Alternatively, you may include your email address in the file if you prefer. Welcome any method of contribution.