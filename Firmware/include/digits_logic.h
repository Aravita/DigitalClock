#ifndef INCLUDE_DIGITS_LOGIC_H_
#define INCLUDE_DIGITS_LOGIC_H_

// Everything related to displaying digits

#include <stdint.h>
#include <stdbool.h>

#define LESSON_0_DIGITS_COUNT 16

#define LESSON_0_DIGITS_MASK 0b00001111
#define LESSON_0_MINUS_MASK 0b01000000
#define LESSON_0_POINT_MASK 0b10000000

#define LESSON_0_CHARACTERS_COUNT 6

// Call me as early as possible
void DigitsLogic_Init();

// Show hexadecimal digit with point
void DigitsLogic_ShowDigit(uint8_t data);

// Show next digit, call me from timer
void DigitsLogic_ShowNextCharacter();

// Set number to display
void DigitsLogic_SetNumberToDisplay(uint8_t number[LESSON_0_CHARACTERS_COUNT]);

#endif /* INCLUDE_DIGITS_LOGIC_H_ */
