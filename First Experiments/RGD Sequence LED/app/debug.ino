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

