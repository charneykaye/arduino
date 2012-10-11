/**
 *
 * @author Nick Kaye
 */

/**
 * advance to next pin
 */
void fadeAdvanceToNextPin()
{
  // set the new 'from' pin to the previous 'to'
  // first run will carry over a -1 value
  pinFadeFrom = pinFadeTo;

  // pick a random pin to fade to that isn't the previous one
  while(pinFadeTo==pinFadeFrom)
    pinFadeTo = pinRandomLED();

  // reset fade position
  fadePosition = 0;
  
  // debug
  DEBUG_fadeAdvanceToNextPin(pinFadeFrom,pinFadeTo);
} 

/**
 * advance fade position 
 */
void fadeRenderAndAdvance()
{
  // set pins based on fade position
  setPinsFromTo( 255-fadePosition, fadePosition );

  // advance fade position
  fadePosition++;

  // end of fade = reset & next pin
  if (fadePosition>=256)
    fadeAdvanceToNextPin();
}

/**
 * Analog write the value of both pins, from and to
 */
void setPinsFromTo(int valFrom, int valTo)
{
  // if fading 'from' a pin, analog write its value
  if (pinFadeFrom>=0)
    analogWrite(pinFadeFrom, valFrom);

  // if fading 'to' a pin, analog write its value
  if (pinFadeTo>=0)
    analogWrite(pinFadeTo, valTo);

  // debug
  DEBUG_setPinsFromTo(pinFadeFrom, valFrom, pinFadeTo, valTo);

  // delay = 1000ms * Total Fade Seconds * 1/255th
  delay(TIME_TOTAL_FADE_SECONDS_SLOW*3.921);
}

/**
 * Random Pin LED
 */
int pinRandomLED() {
  return Lights[random(0,LightCount)]; 
}

