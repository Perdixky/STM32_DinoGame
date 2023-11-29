/*
 * BMP085.c
 *
 *  Created on: Nov 18, 2023
 *      Author: 32937
 */
#include "BMP180.h"
#include "i2c.h"
#include "math.h"


BMP085_InitDataTypdef BMP085_GetInitData(I2C_HandleTypeDef* hi2c)
{
	unsigned char Init_Read_Buffer[22];
	HAL_I2C_Mem_Read(hi2c, BMP085_ADDR, BMP_AC1_ADDR, 1, Init_Read_Buffer, 22, 100);
	BMP085_InitDataTypdef BMP085_InitDataStructure;
	BMP085_InitDataStructure.AC1 = Init_Read_Buffer[0] << 8 | Init_Read_Buffer[1];
	BMP085_InitDataStructure.AC2 = Init_Read_Buffer[2] << 8 | Init_Read_Buffer[3];
	BMP085_InitDataStructure.AC3 = Init_Read_Buffer[4] << 8 | Init_Read_Buffer[5];
	BMP085_InitDataStructure.AC4 = Init_Read_Buffer[6] << 8 | Init_Read_Buffer[7];
	BMP085_InitDataStructure.AC5 = Init_Read_Buffer[8] << 8 | Init_Read_Buffer[9];
	BMP085_InitDataStructure.AC6 = Init_Read_Buffer[10] << 8 | Init_Read_Buffer[11];
	BMP085_InitDataStructure.B1 = Init_Read_Buffer[12] << 8 | Init_Read_Buffer[13];
	BMP085_InitDataStructure.B2 = Init_Read_Buffer[14] << 8 | Init_Read_Buffer[15];
	BMP085_InitDataStructure.MB = Init_Read_Buffer[16] << 8 | Init_Read_Buffer[17];
	BMP085_InitDataStructure.MC = Init_Read_Buffer[18] << 8 | Init_Read_Buffer[19];
	BMP085_InitDataStructure.MD = Init_Read_Buffer[20] << 8 | Init_Read_Buffer[21];
	return BMP085_InitDataStructure;
}

BMP085_OriginalDataTypdef BMP085_GetOriginalData(I2C_HandleTypeDef* hi2c, const char OSS)
{
	BMP085_OriginalDataTypdef BMP085_OriginalDataStructure;
	unsigned char UPMode = BMP_COVERT_PRES + (OSS << 6);
	HAL_I2C_Mem_Write(hi2c, BMP085_ADDR, CONTROL_REG_ADDR, 1, &UPMode, 1, 10);//切换为压强读取，标准模式
	HAL_Delay(7);
	unsigned char Pres_Read_Buffer[3];
	HAL_I2C_Mem_Read(hi2c, BMP085_ADDR, BMP_TEMP_PRES_DATA_REG, 1, Pres_Read_Buffer, 1, 10);

	unsigned char UTMode = BMP_COVERT_TEMP;
	HAL_I2C_Mem_Write(hi2c, BMP085_ADDR, CONTROL_REG_ADDR, 1, &UTMode, 1, 10);//切换为温度读取
	HAL_Delay(4);
	unsigned char Temp_Read_Buffer[2];
	HAL_I2C_Mem_Read(hi2c, BMP085_ADDR, BMP_TEMP_PRES_DATA_REG, 1, Pres_Read_Buffer, 2, 10);

	BMP085_OriginalDataStructure.UP = (Pres_Read_Buffer[0] << 16 | Pres_Read_Buffer[1] << 8 | Pres_Read_Buffer[2]) >> (8 - OSS);
	BMP085_OriginalDataStructure.UT = Temp_Read_Buffer[0] << 8 | Temp_Read_Buffer[1];
	return BMP085_OriginalDataStructure;
}

BMP085_DataTypdef BMP085_GetData(I2C_HandleTypeDef* hi2c, const BMP085_InitDataTypdef* Init_Data, const char OSS)
{
	BMP085_OriginalDataTypdef BMP085_OringinalData = BMP085_GetOriginalData(hi2c, OSS);
	BMP085_DataTypdef BMP085_DataStructure;

	short TX1 = (BMP085_OringinalData.UT - Init_Data->AC6) * Init_Data->AC5 / (1 << 15);
	short TX2 = Init_Data->MC * (1 << 11) / (TX1 + Init_Data->MD);
	BMP085_DataStructure.Temp = (TX1 + TX2 + 8) / 160;

	short B6 = TX1 + TX2 - 4000;
	short PX1 = (Init_Data->B2 * (B6 * B6 / (1 << 12))) / (1 << 11);
	short PX2 = Init_Data->AC2 * B6 / (1 << 11);
	short B3 = (((Init_Data->AC1 * 4 + PX1 + PX2) << OSS) + 2) / 4;
	PX1 = Init_Data->AC3 * B6 / (1 << 13);
	PX2 = (Init_Data->B1 * (B6 * B6 / (1 << 12))) / (1 << 16);
	short PX3 = (PX1 + PX2 + 2) / 4;
	int B4 = Init_Data->AC4 * (unsigned int)(PX3 + 32768) / (1 << 15);
	int B7 = ((unsigned int)BMP085_OringinalData.UP - B3) * (50000 >> OSS);
	int p;
	if (B7 < 0x80000000) p = (B7 * 2) / B4;
		else p = (B7 / B4) * 2;
	PX1 = (p / (1 << 8)) * (p / (1 << 8));
	PX1 = (PX1 * 3038) / (1 << 16);
	PX2 = (-7357 * p) / (1 << 16);
	BMP085_DataStructure.Pres = p + (PX1 + PX2 + 3791) / 16;
	return BMP085_DataStructure;
}

double BMP085_GetAltitude(const int pressure)
{
	return 44330*(1 - pow(pressure / 101325, 1 / 5.255));
}
