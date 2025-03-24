# RaspberryPi-Arduino-SPI-Comm
Contains Raspberry Pi and Arduino applications. The purpose of the applications is to perform data transfers between Raspberry Pi and Arduino using SPI communication.
The repository contains four applications that perform data transfers between Raspberry Pi and Arduino using SPI communication. The applications are as follows:

- BidirectionalComm: Arduino and Raspberry Pi send and receive data to and from each other using SPI communication.

- BidirectionalComm-FIFO: Arduino and Raspberry Pi send and receive data to and from each other using SPI communication with FIFO logic.

- RPiReceiver-ArduinoSender: Raspberry Pi receives data from Arduino. Arduino sends data to Raspberry Pi.

- RPiSender-ArduinoReceiver: Raspberry Pi sends data to Arduino. Arduino receives data from Raspberry Pi.

RaspberryPi Applications:

- Programming Language: C++ Programming Language

- Framework: Qt5 - Qt 5.11.3

- IDE: Qt Creator 4.8.2

- Device: Raspberry Pi-3, Raspberry Pi-4

- Library: To compile the Arduino code in the "BidirectionalCommunication-FIFO" application, you need to load the "CircularBuffer.zip" library into the Arduino IDE.

Arduino Applications:

- Programming Language: C/C++ Programming Language

- IDE: Arduino IDE Version - 2.2.0

- Arduino Used: Arduino Uno

- Arduino Connection Diagram: The Arduino's SPI pins are connected to the Raspberry Pi's SPI pins.