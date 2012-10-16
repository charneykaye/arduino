/**
 *
 * @author Nick Kaye
 */

// Variables will change:
int nsValue;             // the current reading from the input pin
int nsLastValue = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long nsLastDebounceTime = 0;  // the last time the output pin was toggled

/**
 * Numswitch Setup
 */
void numswitchSetup()
{
  // numswitch pins for input
  pinMode(PIN_NUMSWITCH_BINARY_ONE, INPUT);
  pinMode(PIN_NUMSWITCH_BINARY_TWO, INPUT);
  pinMode(PIN_NUMSWITCH_BINARY_FOUR, INPUT);
  pinMode(PIN_NUMSWITCH_BINARY_EIGHT, INPUT);
}

/**
 * Debounce 
 */
void numswitchCheck()
{
    
  // read the state of the switch into a local variable:
  int reading =
    ( digitalRead(PIN_NUMSWITCH_BINARY_ONE) == HIGH ? 1 : 0 ) +
    ( digitalRead(PIN_NUMSWITCH_BINARY_TWO) == HIGH ? 2 : 0 ) +
    ( digitalRead(PIN_NUMSWITCH_BINARY_FOUR) == HIGH ? 4 : 0 ) +
    ( digitalRead(PIN_NUMSWITCH_BINARY_EIGHT) == HIGH ? 8 : 0);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  // reset the debouncing timer
  if (reading != nsLastValue)
    nsLastDebounceTime = millis();  

  // whatever the reading is at, it's been there for longer
  // than the debounce delay, so take it as the actual current state:
  if ((millis() - nsLastDebounceTime) > NUMSWITCH_DEBOUNCE_DELAY_MILLIS)
    numswitchSetNumber(reading);

  // save the reading.  Next time through the loop,
  // it'll be the buttonLastState:
  nsLastValue = reading; 
}

/**
 * After debouncing, new button state has occurred
 */
void numswitchSetNumber(int num)
{
  // no change? skip
  if (nsValue == num)
    return;

  // set variable
  nsValue = num;

  // debug
  DEBUG_numswitchNumber(
  digitalRead(PIN_NUMSWITCH_BINARY_ONE),
  digitalRead(PIN_NUMSWITCH_BINARY_TWO),
  digitalRead(PIN_NUMSWITCH_BINARY_FOUR),
  digitalRead(PIN_NUMSWITCH_BINARY_EIGHT),  
  nsValue);
}

/**
 * Sanitize HIGH / LOW value of button state
 */
boolean numswitchValue()
{
  return nsValue;
}




