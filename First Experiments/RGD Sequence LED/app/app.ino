/**
 *
 * @author Nick Kaye
 */

/**
 * Constants
 */

// length (seconds) of a fade from one pin to the next
const int TIME_TOTAL_FADE_SECONDS_FAST = .1;
const int TIME_TOTAL_FADE_SECONDS_SLOW = 1;

// what pin is each LED connected to
const int PIN_LED_WHITE = 5;
const int PIN_LED_YELLOW = 6;
const int PIN_LED_RED = 9;
const int PIN_LED_GREEN = 10;
const int PIN_LED_BLUE = 11;

// what pin the pushbutton is connected to
const int PIN_PUSHBUTTON = 7;

// array of LED pins to setup, with a hard-coded total
const int Lights[] = {
  PIN_LED_WHITE,
  PIN_LED_YELLOW,
  PIN_LED_RED,
  PIN_LED_GREEN,
  PIN_LED_BLUE
};
const int LightCount = 5;

/**
 * Variables
 */

// all-purpose counter
int i = 0;        

// pin to fade from / to
int pinFadeFrom = -1;
int pinFadeTo = -1;

// fade position
int fadePosition = 0;

// is moving fast?
boolean isMovingFast = false;

/**
 * Setup
 */
void setup() {

  // init serial output for debugging
  Serial.begin(9600);

  // for each LED's pin, tell Arduino it's an output
  for (i = 0; i < LightCount; i++) 
    setupPinAsLED(Lights[i]);
    
  // advance to the first pin
  fadeAdvanceToNextPin();
}

/**
 * Loop
 */
void loop(){
  // do the fade from pin to pin
  fadeRenderAndAdvance();
}




