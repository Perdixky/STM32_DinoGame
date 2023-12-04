/*
 * HMC5883L.h
 *
 *  Created on: Nov 17, 2023
 *      Author: 32937
 */

#ifndef PERIPHERALS_HMC5883L_HMC5883L_H_
#define PERIPHERALS_HMC5883L_HMC5883L_H_

#include "HMC5883L_Reg.h"
#include "i2c.h"

typedef struct{
	short MagX;
	short MagY;
	short MagZ;
}HMC5883L_DataTypedef;

void HMC5883L_INIT(I2C_HandleTypeDef* hi2c);
HMC5883L_DataTypedef HMC5883L_GetData(I2C_HandleTypeDef* hi2c);

#endif /* PERIPHERALS_HMC5883L_HMC5883L_H_ */
