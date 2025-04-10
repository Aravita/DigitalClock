/*
 * rtc.c
 *
 *  Created on: Apr 9, 2025
 *      Author: aravita
 */

#include "rtc.h"
#include "hal.h"

void Lesson0_RTC_PollRTC(void)
{
	if (HAL_OK != HAL_RTC_GetDate(&RtcHandle, &CurrentDate, RTC_FORMAT_BCD))
	{
		Lesson0_HAL_Error();
	}

	if (HAL_OK != HAL_RTC_GetTime(&RtcHandle, &CurrentTime, RTC_FORMAT_BCD))
	{
		Lesson0_HAL_Error();
	}
}

void Lesson0_RTC_Init(void)
{
	RtcHandle.Instance = RTC;
	RtcHandle.Init.AsynchPrediv = 127;
	RtcHandle.Init.SynchPrediv = (LSE_VALUE / 128) - 1;
	RtcHandle.Init.HourFormat = RTC_HOURFORMAT_24;
	RtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;

	if (HAL_OK != HAL_RTC_Init(&RtcHandle))
	{
		Lesson0_HAL_Error();
	}

	/* Resetting date/time */
	CurrentDate.Year = 24U;
	CurrentDate.Month = RTC_MONTH_DECEMBER;
	CurrentDate.Date = 31U;
	CurrentDate.WeekDay = RTC_WEEKDAY_TUESDAY;

	if (HAL_OK != HAL_RTC_SetDate(&RtcHandle, &CurrentDate, RTC_FORMAT_BIN))
	{
		Lesson0_HAL_Error();
	}

	CurrentTime.Hours = 23U;
	CurrentTime.Minutes = 59U;
	CurrentTime.Seconds = 45U;

	if (HAL_OK != HAL_RTC_SetTime(&RtcHandle, &CurrentTime, RTC_FORMAT_BIN))
	{
		Lesson0_HAL_Error();
	}
}

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc)
{
	/* Clocking in backup domain */
	__PWR_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();

	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_BACKUPRESET_FORCE();
	__HAL_RCC_BACKUPRESET_RELEASE();

	/* LSE (32768 Hz crystal) as clock source*/
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_OFF;
	if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Lesson0_HAL_Error();
	}

	/* Clocking in RTC */
	__HAL_RCC_RTC_CLKPRESCALER(RCC_RTCCLKSOURCE_LSE);
	__HAL_RCC_RTC_CONFIG(RCC_RTCCLKSOURCE_LSE);
	__HAL_RCC_RTC_ENABLE();

}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc)
{
	__HAL_RCC_RTC_DISABLE();
}
