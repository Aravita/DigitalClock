/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "diag/trace.h"

#include "global_variables.h"

#include "timer.h"

#include "hal.h"
#include "digits_logic.h"
#include "rtc.h"
#include "main.h"

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[])
{

  timer_start();

  Lesson0_HAL_HardwareInit();

  DigitsLogic_Init();



  // Infinite loop
  while (true)
  {
	  Lesson0_RTC_PollRTC();

	  uint8_t digitsToDisplay[LESSON_0_CHARACTERS_COUNT];

//	  PrepareDateToDisplay(digitsToDisplay);

	  PrepareTimeToDisplay(digitsToDisplay);

	  DigitsLogic_SetNumberToDisplay(digitsToDisplay);
  }
  // Infinite loop, never return.
}

void PrepareTimeToDisplay(uint8_t digits[LESSON_0_CHARACTERS_COUNT])
{
	digits[0] = CurrentTime.Seconds & 0b00001111;
	digits[1] = (CurrentTime.Seconds & 0b11110000) >> 4;

	digits[2] = CurrentTime.Minutes & 0b00001111;
	digits[3] = (CurrentTime.Minutes & 0b11110000) >> 4;

	digits[4] = CurrentTime.Hours & 0b00001111;
	digits[5] = (CurrentTime.Hours & 0b11110000) >> 4;
}

void PrepareDateToDisplay(uint8_t digits[LESSON_0_CHARACTERS_COUNT])
{
	digits[0] = CurrentDate.Year & 0b00001111;
	digits[1] = (CurrentDate.Year & 0b11110000) >> 4;

	digits[2] = (CurrentDate.Month & 0b00001111) | LESSON_0_HAL_DIGIT_POINT;
	digits[3] = (CurrentDate.Month & 0b11110000) >> 4;

	digits[4] = (CurrentDate.Date & 0b00001111) | LESSON_0_HAL_DIGIT_POINT;
	digits[5] = (CurrentDate.Date & 0b11110000) >> 4;
}

#pragma GCC diagnostic pop


// ----------------------------------------------------------------------------
