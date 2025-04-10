/*
 * rtc.h
 *
 *  Created on: Apr 9, 2025
 *      Author: aravita
 */

#ifndef INCLUDE_RTC_H_
#define INCLUDE_RTC_H_

#include <stm32f4xx.h>
#include <stm32f4xx_hal.h>

/**
 * RTC handle
 */
extern RTC_HandleTypeDef RtcHandle;

/*************************
 * Current date and time *
 *************************/
extern RTC_TimeTypeDef CurrentTime;
extern RTC_DateTypeDef CurrentDate;

/* Prepare RTC to work */
void Lesson0_RTC_Init();

/* Put date and time to CurrentTime and CurrentDate*/
void Lesson0_RTC_PollRTC();


#endif /* INCLUDE_RTC_H_ */
