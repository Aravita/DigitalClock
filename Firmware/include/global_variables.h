/*
 * global_variables.h
 *
 *  Created on: Apr 9, 2025
 *      Author: aravita
 */

#ifndef GLOBAL_VARIABLES_H_
#define GLOBAL_VARIABLES_H_

#include <stm32f4xx.h>
#include <stm32f4xx_hal.h>

/**
 * RTC handle
 */
RTC_HandleTypeDef RtcHandle = { 0 };

/*************************
 * Current date and time *
 *************************/
RTC_TimeTypeDef CurrentTime;
RTC_DateTypeDef CurrentDate;



#endif /* GLOBAL_VARIABLES_H_ */
