#ifndef INCLUDE_HAL_H_
#define INCLUDE_HAL_H_

#include <stdint.h>

#define LESSON_0_HAL_DIGIT_0 0b00111111
#define LESSON_0_HAL_DIGIT_1 0b00000110
#define LESSON_0_HAL_DIGIT_2 0b01011011
#define LESSON_0_HAL_DIGIT_3 0b01001111
#define LESSON_0_HAL_DIGIT_4 0b01100110
#define LESSON_0_HAL_DIGIT_5 0b01101101
#define LESSON_0_HAL_DIGIT_6 0b01111101
#define LESSON_0_HAL_DIGIT_7 0b00000111
#define LESSON_0_HAL_DIGIT_8 0b01111111
#define LESSON_0_HAL_DIGIT_9 0b01101111
#define LESSON_0_HAL_DIGIT_A 0b01110111
#define LESSON_0_HAL_DIGIT_B 0b01111100
#define LESSON_0_HAL_DIGIT_C 0b00111001
#define LESSON_0_HAL_DIGIT_D 0b01011110
#define LESSON_0_HAL_DIGIT_E 0b01111001
#define LESSON_0_HAL_DIGIT_F 0b01110001
#define LESSON_0_HAL_DIGIT_MINUS 0b01000000
#define LESSON_0_HAL_DIGIT_POINT 0b10000000

/* Use this function to init hardware */
void Lesson0_HAL_HardwareInit(void);

/* Show data byte on LEDs*/
void Lesson0_HAL_ShowByte(uint8_t data);

/* Light selected digit */
void Lesson0_HAL_LightDigit(uint8_t digit);

/* Initialize digits timer */
void Lesson0_HAL_InitDigitsTimer();

#endif /* INCLUDE_HAL_H_ */
