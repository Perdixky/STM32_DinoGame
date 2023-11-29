/*
 * BMP085.h
 *
 *  Created on: Nov 18, 2023
 *      Author: 32937
 */

#ifndef PERIPHERALS_BMP085_BMP085_H_
#define PERIPHERALS_BMP085_BMP085_H_

#include "BMP180_Reg.h"
#include "i2c.h"

typedef struct{
	short AC1;
	short AC2;
	short AC3;
	short AC4;
	short AC5;
	short AC6;
	short B1;
	short B2;
	short MB;
	short MC;
	short MD;
}BMP085_InitDataTypdef;

typedef struct{
	int   UP;
	short UT;
}BMP085_OriginalDataTypdef;

typedef struct{
	unsigned int Pres;     // Pa
	double Temp;  // ℃
}BMP085_DataTypdef;

BMP085_InitDataTypdef BMP085_GetInitData(I2C_HandleTypeDef* hi2c);

BMP085_OriginalDataTypdef BMP085_GetOriginalData(I2C_HandleTypeDef* hi2c, const char OSS);

BMP085_DataTypdef BMP085_GetData(I2C_HandleTypeDef* hi2c, const BMP085_InitDataTypdef* Init_Data, const char OSS);
/* 在这里用OSS调节工作模式，分为
 *     MODE                   OSS        CONVERSATION TIME
 * ultra low power             0               4.5ms
 * standard                    1               7.5ms
 * high resolution             2               13.5ms
 * ultra high resolution       3               25.5ms
 *
 */

double BMP085_GetAltitude(const int pressure);

#endif /* PERIPHERALS_BMP085_BMP085_H_ */
