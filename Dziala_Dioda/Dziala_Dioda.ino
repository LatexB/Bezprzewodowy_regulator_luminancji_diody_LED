// A very simple Serial-over-BT app that reads input from the host and CAPITALIZES it.
// Released to the public domain by Earle F. Philhower, III, in February 2023

// Under Linux to connect to the PicoW
// 1. Pair to the "PicoW Serial XX:XX..." device using your favorite GUI, entering a PIN of "0000"
// 2. Execute "sudo rfcomm bind 0 00:00:00:00:00:00" to make a `/dev/rfcomm0" device, replacing the "00:00.." with the MAC as listed in the device name
// 3. Run "minicom -D /dev/rfcomm0" and type away
// 4. To remove the virtual serial port, execute "sudo rfcomm release rfcomm0"

// Under Windows to connect to the PicoW
// 1. Pair to the "PicoW Serial XX:XX..." device using the copntrol panel, ignoring any PIN it says to check for
// 2. At this point you will have a new COM: port.  You may need to use the Device Manager to find it's number.
// 3. Open up COMX: in your favorite terminal application and type away

// Under Mac to connect to the PicoW
// 1. Sorry, you're on your own.  If you have a Mac and can update this demo with a Pull Request it would be appreciated!


#include <SerialBT.h>
int ledPin = 14;
int c;
int d=0;
void setup() {
  SerialBT.begin();
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (SerialBT) {
    while (SerialBT.available()) {
      c = SerialBT.read();
      analogWrite(ledPin, c);
    } 
  }
}
