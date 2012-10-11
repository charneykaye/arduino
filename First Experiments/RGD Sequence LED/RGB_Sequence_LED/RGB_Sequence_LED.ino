/**
 *
 * @author Nick Kaye
 */

// length (seconds) of a fade from one pin to the next
const int TIME_TOTAL_FADE_SECONDS = 1;

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
  PIN_LED_WHITE
  PIN_LED_YELLOW,
  PIN_LED_RED,
  PIN_LED_GREEN,
  PIN_LED_BLUE,
};
const int LightCount = 5;

// all-purpose counter
int i = 0;        

// pin to fade from / to
int pinFadeFrom = -1;
int pinFadeTo = -1;

/**
 * Setup
 */
void setup() {

  // init serial output for debugging
  Serial.begin(9600);

  // for each LED's pin, tell Arduino it's an output
  for (i = 0; i < LightCount; i++) 
    setupPinLED(Lights[i]);
}

/**
 * Setup a single LED pin #
 */
void setupPinLED(int Pin) {

  // Debugging
  Serial.print("Setup Pin #" );
  Serial.print(Pin);
  Serial.print(" as LED\n");

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

  // delay
  delay(200);

}  

/**
 * Loop
 */
void loop(){

  // set the new 'from' pin to the previous 'to'
  // first run will carry over a -1 value
  pinFadeFrom = pinFadeTo;

  // pick a random pin to fade to that isn't the previous one
  while(pinFadeTo==pinFadeFrom)
    pinFadeTo = pinRandomLED();

  // do the fade from pin to pin
  fadePinFromTo(); 
}

/**
 * Fade from pin to pin
 */
void fadePinFromTo() {

  // Debugging
  Serial.print("Fade Pin From #" );
  Serial.print(pinFadeFrom);
  Serial.print(" to #");
  Serial.print(pinFadeTo);
  Serial.print("\n");

  // Iterate through the fade and set both pins at a time
  // to values that fade from high to low and vice-versa
  for (i = 0; i < 256; i++)
    setPinsFromTo(
    255-i,
    i
      );

}

/**
 * Analog write the value of both pins, from and to
 */
void setPinsFromTo(int valFrom, int valTo) {

  // Debugging
  /*
  Serial.print("Set Pins #" );
   Serial.print(pinFadeFrom);
   Serial.print(" = ");
   Serial.print(valFrom);
   Serial.print(" and ");
   Serial.print(pinFadeTo);
   Serial.print(" = ");
   Serial.print(valTo);
   Serial.print("\n");
   */

  // if fading 'from' a pin, analog write its value
  if (pinFadeFrom>=0)
    analogWrite(pinFadeFrom, valFrom);

  // if fading 'to' a pin, analog write its value
  if (pinFadeTo>=0)
    analogWrite(pinFadeTo, valTo);

  // delay = 1000ms * Total Fade Seconds * 1/255th
  delay(TIME_TOTAL_FADE_SECONDS*3.921);
}

/**
 * Random Pin LED
 */
int pinRandomLED() {
  return Lights[random(0,LightCount)]; 
}


