/*
 * MPU6050.h
 *
 *  Created on: Nov 15, 2023
 *      Author: 32937
 */

#ifndef PERIPHERALS_MPU6050_MPU6050_H_
#define PERIPHERALS_MPU6050_MPU6050_H_

#include "i2c.h"
#include "MPU6050_Reg.h"

typedef struct{
	short AccX;
	short AccY;
	short AccZ;
	short GyroX;
	short GyroY;
	short GyroZ;
}MPU6050_DataTypdef;

void MPU6050_INIT(I2C_HandleTypeDef* hi2c);
MPU6050_DataTypdef MPU6050_GetData(I2C_HandleTypeDef* hi2c);

#endif /* PERIPHERALS_MPU6050_MPU6050_H_ */
