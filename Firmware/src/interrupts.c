/*
 * interrupts.c
 *
 *  Created on: Apr 10, 2025
 *      Author: aravita
 */

#include <stm32f4xx_hal.h>

#include "interrupts.h"
#include "main.h"
#include "hal.h"

extern uint32_t DateTimeCycleCounter;

void SysTick_Handler(void)
{
  HAL_IncTick();

  if (DateTimeCycleCounter >= TIME_CYCLE_DURATION + DATE_CYCLE_DURATION - 1)
  {
	  DateTimeCycleCounter = 0;
  }
  else
  {
	  DateTimeCycleCounter ++;
  }
}
