/**
 *
 * @author Nick Kaye
 */

/**
 * Setup a single LED pin #
 */
void setupPinAsLED(int Pin) {
  // setup Pin
  pinMode(Pin, OUTPUT);

  // turn Pin on low
  analogWrite(Pin, 33);

  // delay
  delay(200);

  // turn Pin on full
  analogWrite(Pin, 255);

  // delay
  delay(200);

  // turn Pin off
  analogWrite(Pin, 0);

  // debug
  DEBUG_setupPinAsLED(Pin);

  // delay
  delay(200);

}  

