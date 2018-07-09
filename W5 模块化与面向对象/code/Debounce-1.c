/*
  Debounce

  Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
  press), the output pin is toggled from LOW to HIGH or HIGH to LOW. There's a
  minimum delay between toggles to debounce the circuit (i.e. to ignore noise).

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  - Note: On most Arduino boards, there is already an LED on the board connected
    to pin 13, so you don't need any extra components for this example.

  created 21 Nov 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Limor Fried
  modified 28 Dec 2012
  by Mike Walters
  modified 30 Aug 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

boolean isKeyPressed()
{
  static int btnState = HIGH;
  static unsigned long lastDebounceTime = 0;  // the last time the button pin was toggled
  static boolean isValid = false;
  static const unsigned long debounceDelay = 50;
  int reading = digitalRead(buttonPin);
  int ret = false;
  
  // If the switch changed, due to noise or pressing:
  if ( reading != btnState ) {
    lastDebounceTime = millis();
    if ( isValid ) {
      //  was valid and released now
      ret = true;
    }
    isValid = false;
    btnState = reading;
  }

  if ( reading == LOW && (millis() - lastDebounceTime) > debounceDelay ) {
    //  been pressed longer enough
    isValid = true;
  }

  return ret;
}

void loop() {
  static int btnState = HIGH;
  if ( isKeyPressed(theBtn) ) {
    btnState = !btnState;
  }

  // set the LED:
  digitalWrite(ledPin, btnState);
}
