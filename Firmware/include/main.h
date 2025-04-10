/*
 * main.h
 *
 *  Created on: Apr 10, 2025
 *      Author: aravita
 */

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

#include <stdint.h>
#include "digits_logic.h"
#include "interrupts.h"

#define TIME_CYCLE_DURATION 5000
#define DATE_CYCLE_DURATION 5000

void PrepareTimeToDisplay(uint8_t digits[LESSON_0_CHARACTERS_COUNT]);

void PrepareDateToDisplay(uint8_t digits[LESSON_0_CHARACTERS_COUNT]);

#endif /* INCLUDE_MAIN_H_ */
