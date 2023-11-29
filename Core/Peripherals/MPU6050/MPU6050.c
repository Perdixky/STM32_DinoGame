/*
 * MPU6050.c
 *
 *  Created on: Nov 15, 2023
 *      Author: 32937
 */

#include "MPU6050.h"
#include "usart.h"

void MPU6050_INIT(I2C_HandleTypeDef* hi2c)
{
	unsigned char init_data = 0x09;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_PWR_MGMT_1, 1, &init_data, 1, 10);// 0000 1001  第四位置位失能温度，最后三位001使用陀螺仪时钟（推荐）
	init_data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_PWR_MGMT_2, 1, &init_data, 1, 10);//不休眠
	init_data = 0x09;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_SMPLRT_DIV, 1, &init_data, 1, 10);//10分频
	init_data = 0x06;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_CONFIG, 1, &init_data, 1, 10);//最后三位110六级低通滤波
	init_data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_GYRO_CONFIG, 1, &init_data, 1, 10);//最大角速度±250°/s
	init_data = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU6050_ADDRESS, MPU6050_ACCEL_CONFIG, 1, &init_data, 1, 10);//最大加速度2g
}

MPU6050_DataTypdef MPU6050_GetData(I2C_HandleTypeDef* hi2c)
{
	unsigned char Acc_Read_Buffer[6];
	unsigned char Gyro_Read_Buffer[6];
	MPU6050_DataTypdef MPU6050_DataStructure;
	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDRESS, MPU6050_ACCEL_XOUT_H, 1, Acc_Read_Buffer, 6, 10);
	HAL_I2C_Mem_Read(hi2c, MPU6050_ADDRESS, MPU6050_GYRO_XOUT_H, 1, Gyro_Read_Buffer, 6, 10);
	MPU6050_DataStructure.AccX = Acc_Read_Buffer[0] << 8 | Acc_Read_Buffer[1];
	MPU6050_DataStructure.AccY = Acc_Read_Buffer[2] << 8 | Acc_Read_Buffer[3];
	MPU6050_DataStructure.AccZ = Acc_Read_Buffer[4] << 8 | Acc_Read_Buffer[5];
	MPU6050_DataStructure.GyroX = Gyro_Read_Buffer[0] << 8 | Gyro_Read_Buffer[1];
	MPU6050_DataStructure.GyroY = Gyro_Read_Buffer[2] << 8 | Gyro_Read_Buffer[3];
	MPU6050_DataStructure.GyroZ = Gyro_Read_Buffer[4] << 8 | Gyro_Read_Buffer[5];
	return MPU6050_DataStructure;
}
