#include <stdbool.h>

#include "hal.h"
#include "digits_logic.h"

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

TIM_HandleTypeDef timer3Handler = { 0 };

void Lesson0_HAL_HardwareInit(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStructure = { 0 };

  // PORT A
  GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

  // PORT B
  GPIO_InitStructure.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

  Lesson0_HAL_InitDigitsTimer();
}

/* Show data byte on LEDs*/
void Lesson0_HAL_ShowByte(uint8_t data)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (data & 0b00000001) >> 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (data & 0b00000010) >> 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (data & 0b00000100) >> 2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (data & 0b00001000) >> 3);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (data & 0b00010000) >> 4);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (data & 0b00100000) >> 5);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (data & 0b01000000) >> 6);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (data & 0b10000000) >> 7);
}

void Lesson0_HAL_LightDigit(uint8_t digit)
{
	uint16_t digitsBits[6];
	digitsBits[0] = GPIO_PIN_9;
	digitsBits[1] = GPIO_PIN_10;
	digitsBits[2] = GPIO_PIN_12;
	digitsBits[3] = GPIO_PIN_13;
	digitsBits[4] = GPIO_PIN_14;
	digitsBits[5] = GPIO_PIN_15;

	GPIO_PinState pinState = GPIO_PIN_RESET;

	for (uint8_t i = 0; i < 6; i++)
	{
		if (i == digit)
		{
			pinState = GPIO_PIN_SET;
		}
		else
		{
			pinState = GPIO_PIN_RESET;
		}


		HAL_GPIO_WritePin(GPIOB, digitsBits[i], pinState);
	}
}

void Lesson0_HAL_InitDigitsTimer()
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	timer3Handler.Instance = TIM3;

	timer3Handler.Init.Prescaler = (uint32_t)(SystemCoreClock / 1000) - 1;
	timer3Handler.Init.Period = 10;
	timer3Handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer3Handler.Init.CounterMode = TIM_COUNTERMODE_UP;
	timer3Handler.Init.RepetitionCounter = 0;
	timer3Handler.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if (HAL_OK != HAL_TIM_Base_Init(&timer3Handler))
	{
		while (true) {  }
	}

	HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);


	if (HAL_OK != HAL_TIM_Base_Start_IT(&timer3Handler))
	{
		while (true) {  }
	}
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer3Handler);

	DigitsLogic_ShowNextCharacter();
}

