# RaspberryPi-Arduino-SPI-Communication
Includes applications that facilitate SPI communication between Raspberry Pi and Arduino. Data transfers occur between Raspberry Pi and Arduino.
In the repository, there are four different applications where SPI communication between Raspberry Pi and Arduino takes place. The applications are:

- BidirectionalCommunication: Arduino and Raspberry Pi send and receive data to and from each other via SPI communication.

- BidirectionalCommunication-FIFO: Arduino and Raspberry Pi send and receive data to and from each other using FIFO logic. To compile the Arduino code, load the "CircularBuffer.zip" library found within the application into the Arduino IDE.

- RaspberryPiReceiver-ArduinoSender: Raspberry Pi receives data from Arduino. Arduino sends data to Raspberry Pi.

- RaspberryPiSender-ArduinoReceiver: Raspberry Pi sends data to Arduino. Arduino receives data from Raspberry Pi.

Arduino Used: Arduino Uno, Arduino Mega

Arduino IDE Version: 2.2.0

Raspberry Pi Used: RPI3, RPI4

Raspberry Pi IDE Version: QT IDE

Arduino - Raspberry Pi Connection Diagram: Connections are made through standard SPI pins.