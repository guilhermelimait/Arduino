# Arduino Projects

This repository contains a collection of Arduino projects. These projects demonstrate various applications of the Arduino platform, including sensor interfacing, motor control, and basic electronics. They are intended for hobbyists, students, and anyone interested in learning and experimenting with Arduino.

## Table of Contents

- [Introduction](#introduction)
- [Projects](#projects)
- [How to Use](#how-to-use)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

These Arduino projects explore different aspects of embedded systems development. They provide practical examples of how to interface sensors, control actuators, and build simple electronic circuits using the Arduino platform. I've created these projects to learn about embedded systems and share my knowledge with others.

## Projects

This section provides a brief overview of each project in the repository. For more detailed information on a specific project, please refer to the project's folder and the code within.

*   `BlinkLED`: A simple project that blinks an LED connected to an Arduino pin. Demonstrates basic output control.
*   `UltrasonicDistanceSensor`: Demonstrates how to use an ultrasonic sensor (HC-SR04) to measure distance.
*   `ServoMotorControl`: Controls a servo motor using an Arduino.  Illustrates how to control angular position.
*   `PhotoresistorLightSensor`:  Uses a photoresistor to measure light levels and control an LED's brightness.
*   `TemperatureSensor`: Reads temperature data from a DHT11 or similar temperature/humidity sensor.

## How to Use

Each project contains the Arduino sketch (`.ino` file), a wiring diagram (usually as a PNG image), and sometimes a `README.md` specific to the project with more details.

1.  **Hardware:** Gather the required hardware components, including the Arduino board (e.g., Uno, Nano), sensors (e.g., HC-SR04, DHT11), actuators (e.g., servo motor, LED), resistors, wires, and other electronic components. Refer to the project's wiring diagram for a list of required components.
2.  **Wiring:** Connect the components according to the wiring diagram provided in the project folder. Double-check all connections to avoid damage to your components or Arduino.
3.  **Software:** Open the Arduino IDE (Integrated Development Environment) on your computer. Download and install it if you don't have it already.
4.  **Upload:** Open the `.ino` file for the desired project in the Arduino IDE. Select the correct Arduino board (e.g., Arduino Uno) and the correct port that your Arduino is connected to. Compile and upload the code to your Arduino board.
5.  **Run:** Once the code is uploaded, the project should start running. Observe the behavior of the circuit and the output of the project (e.g., blinking LED, distance readings, servo movement).

## Dependencies

These projects may require specific Arduino libraries. You can install them using the Arduino Library Manager within the Arduino IDE.

1.  Open the Arduino IDE.
2.  Go to Sketch > Include Library > Manage Libraries...
3.  Search for the required library (e.g., `LiquidCrystal`, `Ultrasonic`, `DHT sensor library`).
4.  Install the library.

Libraries used in these projects:

*   `Ultrasonic` (for the UltrasonicDistanceSensor project)
*   `Servo` (for the ServoMotorControl project)
*   `DHT sensor library` (for the TemperatureSensor project)

## Contributing

Contributions are welcome! If you would like to contribute to this project, please submit a pull request or open an issue to discuss your proposed changes.

## License

MIT License

## Contact

Guilherme Lima

༼ つ ◕_◕ ༽つ
WOOHOO
