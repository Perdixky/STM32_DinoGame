/*
 * HMC5883L.c
 *
 *  Created on: Nov 17, 2023
 *      Author: 32937
 */

#include "HMC5883L.h"
#include "usart.h"

void HMC5883L_INIT(I2C_HandleTypeDef* hi2c)
{
	unsigned char init_data = 0x78;//0 11 110 00   采样平均数8  标准数据输出速率75
	HAL_I2C_Mem_Write(hi2c, HMC5883_ADDR, HMC5883_Conf_Reg_A, 1, &init_data, 1, 100);
	init_data = 0x20;//001 00000     增益1090Counts
	HAL_I2C_Mem_Write(hi2c, HMC5883_ADDR, HMC5883_Conf_Reg_B, 1, &init_data, 1, 100);
	init_data = 0x00;//00 000000     连续测量模式
	HAL_I2C_Mem_Write(hi2c, HMC5883_ADDR, HMC5883_Mode_Reg, 1, &init_data, 1, 100);
}

HMC5883L_DataTypedef HMC5883L_GetData(I2C_HandleTypeDef* hi2c)
{
	HMC5883L_DataTypedef HMC5883L_DataStructure;
	unsigned char Mag_Read_Buffer[6];
	HAL_I2C_Mem_Read(hi2c, HMC5883_ADDR, HMC5883_REG_X_MSB, 1, Mag_Read_Buffer, 6, 10);
	HMC5883L_DataStructure.MagX = Mag_Read_Buffer[0] << 8 | Mag_Read_Buffer[1];
	HMC5883L_DataStructure.MagY = Mag_Read_Buffer[2] << 8 | Mag_Read_Buffer[3];
	HMC5883L_DataStructure.MagZ = Mag_Read_Buffer[4] << 8 | Mag_Read_Buffer[5];
	return HMC5883L_DataStructure;
}
