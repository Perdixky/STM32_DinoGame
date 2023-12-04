/*
 * Key.c
 *
 *  Created on: Nov 26, 2023
 *      Author: 32937
 */

#include "Key.h"

/*
 * @bref 获取按键信息（直到松开）
 * @param GPIOx GPIO总线
 * @param GPIO_Pin  引脚
 * @return 读取的信息
 *
 */
char Key_InputData(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
{
	Readagain:
	char kaynum = 0;
	if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin))
	{
		HAL_Delay(6);//等待一段时间来消抖
		if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == 1)//消抖后检测
			kaynum = 1;
		else goto Readagain;
	}
	while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == 1);
	if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == 0)
	{
		HAL_Delay(6);//消抖
		if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == 0)//检测
			return kaynum;
		goto Readagain;
	}
	goto Readagain;
}
