/*
 * BMP085_Reg.h
 *
 *  Created on: Nov 18, 2023
 *      Author: 32937
 */

#ifndef PERIPHERALS_BMP085_BMP085_REG_H_
#define PERIPHERALS_BMP085_BMP085_REG_H_

//地址均为读地址
#define BMP085_ADDR         0xEE      //定义器件在IIC总线中的写地址

#define BMP_AC1_ADDR        0XAA      //定义校准寄存器的地址
#define BMP_AC2_ADDR        0XAC
#define BMP_AC3_ADDR        0XAE
#define BMP_AC4_ADDR        0XB0
#define BMP_AC5_ADDR        0XB2
#define BMP_AC6_ADDR        0XB4
#define BMP_B1_ADDR         0XB6
#define BMP_B2_ADDR         0XB8
#define BMP_MB_ADDR         0XBA
#define BMP_MC_ADDR         0XBC
#define BMP_MD_ADDR         0XBE

#define CONTROL_REG_ADDR    0XF4    //控制寄存器，在这个寄存器中设置不同的值可以设置不同转换时间,同时不同的值可以确认转换大气压或者温度
#define BMP_COVERT_TEMP     0X2E    //转换温度 4.5MS
#define BMP_COVERT_PRES     0X34    //转换大气压由此值和OSS左移6位相加的值写入实现不同模式


#define BMP_TEMP_PRES_DATA_REG  0XF6    //两个字节温度数据

//0xf6 0xf7 0xf8 压强地址
//0xf6 0xf7 温度地址

#endif /* PERIPHERALS_BMP085_BMP085_REG_H_ */
