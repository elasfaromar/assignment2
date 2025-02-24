# Assignment 2
## Student Information
**Name:** Omar Elasfar
**Student Number:** 101300232

## File List and Descriptions
1. **defs.h**: Contains various definitions and constants used throughout the project.
2. **RGB.h/RGB.cc**: Class for color representation.
3. **TextArea.h/TextArea.cc**: Represents a text display area.
4. **FlowPanel.h/FlowPanel.cc**: Manages a collection of `TextArea` components.
5. **PanelArray.h/PanelArray.cc**: Manages an array of panels.
6. **TAArray.h/TAArray.cc**: Manages an array of text areas.
7. **CuWindow.h/CuWindow.cc**: Handles window creation and management.
8. **View.h/View.cc**: Handles the display logic.
9. **Tester.h/Tester.cc**: Contains the implementation for testing individual components.
10. **TestControl.h/TestControl.cc**: Manages and runs various tests.
11. **main.cc**: Entry point of the application, initializes and starts the test control.
12. **MakeFile**: Script for compiling the project using the `make` command.

## Compilation Instructions
To compile the project, navigate to the project directory and run the following commands:
```sh
make
```

## Execution Instructions
To run the compiled program, use the following command:
```sh
./a2
```

## Additional Details
- Have implemented flow layout to `TextAreas` in `Flowpanls`
- Have implemented text wrapping in `TextAreas`