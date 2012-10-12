/**
 * Master debug switches, comment out to disable a category of debug
 */

// Debugging for every single "loop" frame
// #define DEBUG_FRAME

// Debugging for significant events
#define DEBUG_SIGNIFICANT_EVENT

/**
 * Conditional definitions
 */

/**
 * Fade Pin From #1 to #2
 */
#ifdef DEBUG_SIGNIFICANT_EVENT
#define DEBUG_fadeAdvanceToNextPin(...) PRINT_fadeAdvanceToNextPin(__VA_ARGS__)
#else
#define DEBUG_fadeAdvanceToNextPin(...) /* */
#endif
void PRINT_fadeAdvanceToNextPin(int pinFrom, int pinTo)
{  
  Serial.print("Now Fade Pin From #" );
  Serial.print(pinFadeFrom);
  Serial.print(" to #");
  Serial.print(pinFadeTo);
  Serial.print("\n");
}

/**
 * Set Pins #1 = 2 and #3 = 4
 */
#ifdef DEBUG_FRAME
#define DEBUG_setPinsFromTo(...) PRINT_setPinsFromTo(__VA_ARGS__)
#else
#define DEBUG_setPinsFromTo(...) /* */
#endif
void PRINT_setPinsFromTo(int pinFrom, int valFrom, int pinTo, int valTo)
{
  Serial.print("Set Pins #" );
  Serial.print(pinFrom);
  Serial.print(" = ");
  Serial.print(valFrom);
  Serial.print(" and ");
  Serial.print(pinTo);
  Serial.print(" = ");
  Serial.print(valTo);
  Serial.print("\n");
}

/**
 * Set Meter Pin #1 = 2.222
 */
#ifdef DEBUG_FRAME
#define DEBUG_setMeterPin(...) PRINT_setMeterPin(__VA_ARGS__)
#else
#define DEBUG_setMeterPin(...) /* */
#endif
void PRINT_setMeterPin(int Pin, int valMeter)
{
  Serial.print("Set Meter Pin #" );
  Serial.print(Pin);
  Serial.print(" = ");
  Serial.print(valMeter);
  Serial.print("\n");
}

/**
 * Setup Pin #X as LED
 */
#ifdef DEBUG_SIGNIFICANT_EVENT
#define DEBUG_setupPinAsLED(...) PRINT_setupPinAsLED(__VA_ARGS__)
#else
#define DEBUG_setupPinAsLED(...) /* */
#endif
void PRINT_setupPinAsLED(int Pin)
{
  Serial.print("Setup Pin #" );
  Serial.print(Pin);
  Serial.print(" as LED\n");
}

/**
 * Fade Ratio 1.111 at 2222ms out of 3333ms
 */
#ifdef DEBUG_FRAME
#define DEBUG_fadeRatio(...) PRINT_fadeRatio(__VA_ARGS__)
#else
#define DEBUG_fadeRatio(...) /* */
#endif
void PRINT_fadeRatio( double Ratio )
{
  Serial.print("Fade Ratio " );
  Serial.print(Ratio);
  Serial.print("\n");
}

