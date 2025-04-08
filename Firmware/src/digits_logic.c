#include "digits_logic.h"
#include "hal.h"

uint8_t CharactersToDisplay[LESSON_0_CHARACTERS_COUNT];
uint8_t ActiveCharacter;

void DigitsLogic_Init()
{
	CharactersToDisplay[0] = 0;
	CharactersToDisplay[1] = 0;
	CharactersToDisplay[2] = 0;
	CharactersToDisplay[3] = 0;
	CharactersToDisplay[4] = 0;
	CharactersToDisplay[5] = 0;

	ActiveCharacter = 0;
}

void DigitsLogic_ShowDigit(uint8_t data)
{
	uint8_t digitsTable[LESSON_0_DIGITS_COUNT];

	digitsTable[0] = LESSON_0_HAL_DIGIT_0;
	digitsTable[1] = LESSON_0_HAL_DIGIT_1;
	digitsTable[2] = LESSON_0_HAL_DIGIT_2;
	digitsTable[3] = LESSON_0_HAL_DIGIT_3;
	digitsTable[4] = LESSON_0_HAL_DIGIT_4;
	digitsTable[5] = LESSON_0_HAL_DIGIT_5;
	digitsTable[6] = LESSON_0_HAL_DIGIT_6;
	digitsTable[7] = LESSON_0_HAL_DIGIT_7;
	digitsTable[8] = LESSON_0_HAL_DIGIT_8;
	digitsTable[9] = LESSON_0_HAL_DIGIT_9;
	digitsTable[10] = LESSON_0_HAL_DIGIT_A;
	digitsTable[11] = LESSON_0_HAL_DIGIT_B;
	digitsTable[12] = LESSON_0_HAL_DIGIT_C;
	digitsTable[13] = LESSON_0_HAL_DIGIT_D;
	digitsTable[14] = LESSON_0_HAL_DIGIT_E;
	digitsTable[15] = LESSON_0_HAL_DIGIT_F;

	uint8_t tmp = digitsTable[data & LESSON_0_DIGITS_MASK];

	// Minus check
	if (0 != (data & LESSON_0_MINUS_MASK))
	{
		tmp = LESSON_0_HAL_DIGIT_MINUS;
	}

	// Point check
	if (0 != (data & LESSON_0_POINT_MASK))
	{
		tmp = tmp | LESSON_0_HAL_DIGIT_POINT;
	}

	Lesson0_HAL_ShowByte(tmp);
}

void DigitsLogic_ShowNextCharacter()
{
	ActiveCharacter ++;

	if (ActiveCharacter >= LESSON_0_CHARACTERS_COUNT)
	{
		ActiveCharacter = 0;
	}

	DigitsLogic_ShowDigit(CharactersToDisplay[ActiveCharacter]);

	Lesson0_HAL_LightDigit(ActiveCharacter);
}

void DigitsLogic_SetNumberToDisplay(uint8_t number[LESSON_0_CHARACTERS_COUNT])
{
	for (uint8_t i = 0; i < LESSON_0_CHARACTERS_COUNT; i ++)
	{
		CharactersToDisplay[i] = number[i];
	}
}

