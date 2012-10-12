/**
 *
 * @author Nick Kaye
 */

/**
 * Constants
 */

// length (seconds) of a fade from one pin to the next
const float TIME_TOTAL_FADE_SECONDS_FAST = .1;
const float TIME_TOTAL_FADE_SECONDS_SLOW = 1;

// what pin is each LED connected to
const int PIN_LED_WHITE = 5;
const int PIN_LED_YELLOW = 6;
const int PIN_LED_RED = 9;
const int PIN_LED_GREEN = 10;
const int PIN_LED_BLUE = 11;

// what pin is the voltimeter connected to, or -1 if none
const int PIN_METER = -1;

// what pin the pushbutton is connected to
const int PIN_BUTTON = 7;

// pushbutton debounce time milliseconds; increase if the output flickers
const long BUTTON_DEBOUNCE_DELAY_MILLIS = 50;

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

// all-purpose variables
int i = 0;
int v = 0;

// pin to fade from / to
int pinFadeFrom = -1;
int pinFadeTo = -1;

// fade state variables
int fadePosition = 0;
long fadeStartMillis = 0;
double fadeRatio = 0;
double fadeRatioNum = 0;
double fadeRatioDen = 0;

// is moving fast?
boolean isMovingFast = false;

// is meter ascending?
boolean isMeterAscending = true;

/**
 * Setup
 */
void setup() {

  // init serial output for debugging
  Serial.begin(9600);

  // pushbutton for input
  pinMode(PIN_BUTTON, INPUT);

  // for each LEDs pin, tell Arduino it's an output
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
  
  // check the pushbutton
  buttonCheck();
}




