/*
 * Key.h
 *
 *  Created on: Nov 26, 2023
 *      Author: 32937
 */

#ifndef KEY_H_
#define KEY_H_

#include "gpio.h"

char Key_InputData(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin);

#endif /* KEY_H_ */
