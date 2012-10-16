/**
 *
 * @author Nick Kaye
 */

// Variables will change:
int buttonState;             // the current reading from the input pin
int buttonLastState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled

/**
 * Button Setup
 */
void buttonSetup()
{
  // pushbutton for input
  pinMode(PIN_BUTTON, INPUT);
}

/* 
 Debounce
 
 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).  
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 
 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Debounce
 */
void buttonCheck()
{
    
  // read the state of the switch into a local variable:
  int reading = digitalRead(PIN_BUTTON);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  // reset the debouncing timer
  if (reading != buttonLastState)
    lastDebounceTime = millis();

  // whatever the reading is at, it's been there for longer
  // than the debounce delay, so take it as the actual current state:
  if ((millis() - lastDebounceTime) > BUTTON_DEBOUNCE_DELAY_MILLIS)
    buttonSetState(reading);

  // save the reading.  Next time through the loop,
  // it'll be the buttonLastState:
  buttonLastState = reading; 
}

/**
 * After debouncing, new button state has occurred
 */
void buttonSetState(int newState)
{
  // no change? skip
  if (buttonState == newState)
    return;

  // set variable
  buttonState = newState;

  // if it's turning off, advance to next pin
  if (!isButtonOn())
    fadeAdvanceToNextPin();
}

/**
 * Sanitize HIGH / LOW value of button state
 */
boolean isButtonOn()
{
  return (buttonState == HIGH) ? true : false;
}




