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

typedef {
    int btnPin;
    int btnState;
    int pressedValue;
    unsigned long lastDebounceTime;
    boolean isValid;
    unsigned long debounceDelay;
} Button;

Button theBtn;

void setup() {
  pinMode(ledPin, OUTPUT);
  init_button(&theBtn, 2, true);
  
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

Button* init_button(Button* btn, int pin, boolean pullup)
{
  btn->btnPin = pin;
  btn->btnState = pullup?HIGH:LOW;
  btn->pressedValue = pullup?LOW:HIGH;
  pinMode(pin, pullup?INPUT_PULLUP:INPUT);
  btn->lastDebounceTime = 0;
  btn->isValid = false;
  btn->debounceDelay = 50;
}

boolean isKeyPressed(Button* btn)
{
  int reading = digitalRead(btn->btnMode);
  int ret = false;
  
  // If the switch changed, due to noise or pressing:
  if ( reading != btn->btnState ) {
    btn->lastDebounceTime = millis();
    if ( btn->isValid ) {
      //  was valid and released now
      ret = true;
    }
    btn->isValid = false;
    btn->btnState = reading;
  }

  if ( reading == LOW && (millis() - btn->lastDebounceTime) > btn->debounceDelay ) {
    //  been pressed longer enough
    isValid = true;
  }

  return ret;
}

void loop() {
  static const int ledPin = 13; 
  static int btnState = HIGH;
  if ( isKeyPressed(theBtn) ) {
    btnState = !btnState;
  }

  // set the LED:
  digitalWrite(ledPin, btnState);
}
