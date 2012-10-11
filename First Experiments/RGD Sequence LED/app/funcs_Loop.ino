/**
 *
 * @author Nick Kaye
 */

/**
 * render current fade
 */
void fadeRenderAndAdvance()
{
  // determine fade ratio from current time
  fadeRatioNum =  millis() - fadeStartMillis;
  fadeRatioDen = fadeLengthSeconds() * 1000;
  fadeRatio = fadeRatioNum / fadeRatioDen;

  // debug
  DEBUG_fadeRatio(fadeRatio);

  // end of fade = reset & next pin
  if (fadeRatio>1)
    return fadeAdvanceToNextPin();

  // determine fade position from ratio
  fadePosition = fadeRatio * 256;

  // set pins based on fade position
  setPinsFromTo( 255-fadePosition, fadePosition );
}

/**
 * advance to next pin
 */
void fadeAdvanceToNextPin()
{
  // set pins all the way
  setPinsFromTo( 0, 255 );

  // set the new 'from' pin to the previous 'to'
  // first run will carry over a -1 value
  pinFadeFrom = pinFadeTo;

  // set the start timer to the current clock
  fadeStartMillis = millis();

  // pick a random pin to fade to that isn't the previous one
  while(pinFadeTo==pinFadeFrom)
    pinFadeTo = pinRandomLED();

  // debug
  DEBUG_fadeAdvanceToNextPin(pinFadeFrom,pinFadeTo);
} 

/**
 * Analog write the value of both pins, from and to
 */
void setPinsFromTo(int valFrom, int valTo)
{
  // if fading 'from' a pin, analog write its value
  if (pinFadeFrom>=0)
    analogWrite(pinFadeFrom, valFrom * valFrom / 255);

  // if fading 'to' a pin, analog write its value
  if (pinFadeTo>=0)
    analogWrite(pinFadeTo, valTo * valTo / 255);

  // debug
  DEBUG_setPinsFromTo(pinFadeFrom, valFrom, pinFadeTo, valTo);
}

/**
 * Random Pin LED
 */
int pinRandomLED() {
  return Lights[random(0,LightCount)]; 
}

/**
 * Frame delay milliseconds
 */
float fadeLengthSeconds() {
  return isButtonOn() ? TIME_TOTAL_FADE_SECONDS_FAST : TIME_TOTAL_FADE_SECONDS_SLOW;
}


