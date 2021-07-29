/*
 * PollingRoutines.c
 *
 *  Created on: Mar 24, 2021
 *      Author: koson
 */

#include "main.h"
#include "PollingRoutines.h"
#include "cmsis_os.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern osSemaphoreId binarySemAnalogHandle;

uint32_t uhADCxConvertedValue[10] = { 0 };

void PollingInit()
{
	HAL_ADC_Start_DMA(&hadc1, &uhADCxConvertedValue, 10);
	HAL_TIM_Base_Start_IT(&htim1);
}

void PollingRoutine()
{

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	osSemaphoreRelease(binarySemAnalogHandle);

}
