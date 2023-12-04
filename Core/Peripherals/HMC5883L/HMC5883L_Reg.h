/*
 * HMC5883L_Reg.h
 *
 *  Created on: Nov 17, 2023
 *      Author: 32937
 */

#ifndef PERIPHERALS_HMC5883L_HMC5883L_REG_H_
#define PERIPHERALS_HMC5883L_HMC5883L_REG_H_

#define HMC5883_REG_X_MSB 0x03 //输出X寄存器A中存储测量结果中的MSB（高位数据）
#define HMC5883_REG_X_LSB 0x04 //输出X寄存器B中存储测量结果中的MSB（低位数据）
#define HMC5883_REG_Z_MSB 0x05 //输出Y寄存器A中存储测量结果中的MSB（高位数据）
#define HMC5883_REG_Z_LSB 0x06 //输出Y寄存器B中存储测量结果中的MSB（低位数据）
#define HMC5883_REG_Y_MSB 0x07 //输出Z寄存器A中存储测量结果中的MSB（高位数据）
#define HMC5883_REG_Y_LSB 0x08 //输出Z寄存器B中存储测量结果中的MSB（低位数据）

/* CRA */
#define HMC5883_Conf_Reg_A                   0x00 // default
#define HMC5883_Conf_Reg_B                   0x01
#define HMC5883_Mode_Reg                     0x02

/* read addr*/
#define HMC5883_ADDR                         0x3C //写入地址
/*-------------------------------------------------------------
IIC地址：0x3C
配置寄存器A：0x00 （用于配置该装置设置的数据输出速率和测量配置）
配置寄存器B: 0x01 （用于设置装置的增益）
模式寄存器： 0x02 （用来设定装置的操作模式）
---------------------------------------------------------------*/

#endif /* PERIPHERALS_HMC5883L_HMC5883L_REG_H_ */
