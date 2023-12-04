/*
 * i-Bus.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Perdixky
 */
#include "i-Bus.h"

//接收数据
unsigned char i_BusData[32];



/*
 * @author Perdixky
 * @brief 与接收器进行同步
 * @param huart 串口句柄
 */
void i_Bus_INIT(UART_HandleTypeDef* huart)
{
	unsigned char temp;
	unsigned char abadon[31];
	 do{
		 HAL_UART_Receive(huart, &temp, 1, 100);
	 }while(temp != 0x20);
	 HAL_UART_Receive(huart, abadon, 31, 100);
}

/*
 * @author Perdixky
 * @brief 接收数据，解包，校验
 * @param huart 串口句柄
 */
void i_Bus_Analysis(UART_HandleTypeDef* huart)
{
	if(i_BusData[0] == 0x20 && i_BusData[1] == 0x40)
	{
		unsigned short Check_Sum;
		for(int i = 0; i < 30; i++)
		{
			Check_Sum += i_BusData[i];
		}
		if (Check_Sum == i_BusData[31] << 8 | i_BusData[30])
		{
			unsigned short CH[4];
			for(int i = 0; i < 4; i++)
				CH[i] = (unsigned short)((i_BusData[2 * i + 3] << 8) | i_BusData[2 * i + 2]) & 0x07FF;
			HAL_UART_Transmit(&huart2, i_BusData, 32, 100);
		}

	}
}
