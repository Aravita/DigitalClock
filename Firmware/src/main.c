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

#include "timer.h"

#include "hal.h"
#include "digits_logic.h"

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

  uint8_t currentCharacters[LESSON_0_CHARACTERS_COUNT];
  currentCharacters[0] = 0;
  currentCharacters[1] = 0;
  currentCharacters[2] = 0;
  currentCharacters[3] = 0;
  currentCharacters[4] = 0;
  currentCharacters[5] = 0;

  uint32_t currentNumber = 0;

  // Infinite loop
  while (true)
  {
	  HAL_Delay(1000);

	  currentNumber ++;

	  currentCharacters[0] = currentNumber & 0b1111;
	  currentCharacters[1] = (currentNumber >> 4) & 0b1111;
	  currentCharacters[2] = (currentNumber >> 8) & 0b1111;
	  currentCharacters[3] = (currentNumber >> 12) & 0b1111;
	  currentCharacters[4] = (currentNumber >> 16) & 0b1111;
	  currentCharacters[5] = (currentNumber >> 20) & 0b1111;

	  DigitsLogic_SetNumberToDisplay(currentCharacters);
  }
  // Infinite loop, never return.
}

#pragma GCC diagnostic pop


// ----------------------------------------------------------------------------
