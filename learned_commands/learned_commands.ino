// important imports to know:
#include "pitches.h" // for instrumental notes 

// the setup routine runs once when you press reset
void setup() {
  // in the setup(), its usually used to initialize the pins and their modes. or sometimes to make something work once only.

  // built-in variables:

  LED_BUILTIN                               // the led on the arduino board also could be "pin 13"
  LOW                                       // used to set the state of an led for example to off, represents 0 volts
  HIGH                                      // used to set the state of an led for example to on, represents 0< volts
  OUTPUT                                    // A pin state to mark it as output
  INPUT                                     // A pin state to mark it as input
  INPUT_PULLUP

  // the most important/frequently used methods used in arduinos:

  analogRead(/*e.g. A0*/)                   // reads the input on the analog specified in the ()
  analogWrite(/*pin*/, /*value (0 - 255)*/) // used to send a PWM signal to the pins marked with ~. Useful anytime you need to control power or intensity
  Serial.println(/*anything*/)              // writes to the Tools > Serial Monitor
  Serial.begin(/*in miliseconds*/)          // todo: not sure yet, learn then write
  delay(/*in miliseconds*/)                 // stops the program for a specified moment before it executes the next command
  pinMode(/*the pin*/, /*the mode*/)        // initialize the pin specified to either input or output
  digitalRead()                             // Reads the digital input pin, to store its current value for example
  digitalWrite()                            // todo: not sure yet, learn then write
  millis()                                  // todo: not sure yet, learn then write

  // tips to remember:
      // Generally, you should use "unsigned long" for variables that hold time
      // The value will quickly become too large for an int to store
}

// the loop routine runs over and over again forever:
void loop() {

  // important logic to keep in mind:

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);

  // toggle an led if the button is pushed:
  // reading = digitalRead(buttonPin)
  // buttonState;
  if (reading != buttonState) {
    buttonState = reading;

    // only toggle the LED if the new button state is HIGH
    if (buttonState == HIGH) {
      ledState = !ledState;
    }
  }

  // turn the led on when the button is pushed 4 times:
  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
