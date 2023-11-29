/*
 * Dino_Game.c
 *
 *  Created on: Nov 25, 2023
 *      Author: 32937
 */

#include "Dino_Game.h"

/*
 * @brief 上升沿中断回调函数检测引脚电平
 * @author Perdixky
 *
 * @note 按键一端连接PA12（下拉输入模式），一端连接高电平
 */
char Key_DataBuffer = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_12)
	{
		Key_DataBuffer = Key_InputData(GPIOA, GPIO_PIN_12);
	}
}

//得分
unsigned short Score = 0;

//恐龙高度由Jump_Hight[Dinosaur_Hight]得出
unsigned char Dinosaur_Hight = 0;

//小恐龙状态
char Dinosaur_state = Running;

//0.8s 跳跃时长的抛物线近似值
const unsigned char Jump_Hight[21] = { 40, 33, 27, 22, 17, 12, 8, 5, 3, 1, 0, 1, 3, 5,  8, 12, 17, 22, 27, 33, 40 };

//根据程序，屏幕中最多同时出现两个障碍物
Big_Tree Big_Tree_1, Big_Tree_2;
Small_Tree Small_Tree_1, Small_Tree_2;
Bird Bird_1, Bird_2;

void

void Dino_Run()
{
	static char run = 0;
	if(run == 0)
	{
		OLED_DrawImage(2, 40, &dino_front_legImg, OLED_COLOR_NORMAL);
		run = 1;
	}
	else
	{
		OLED_DrawImage(2, 40, &dino_back_legImg, OLED_COLOR_NORMAL);
		run = 0;
	}
}

//void Dino_Jump()
//{
//	for (unsigned char x = 0; x < 21; x++)
//	{
//		OLED_DrawFilledRectangle(2, Jump_Hight[x > 0 ? x - 1 : x], 21, 23, OLED_COLOR_REVERSED);//清除上一个时间的小恐龙位置
//		Dinosaur_Hight = Jump_Hight[x];
//		OLED_DrawImage(2, Jump_Hight[x], &dino_jumpsImg, OLED_COLOR_NORMAL);
//		OLED_ShowFrame();
//		HAL_Delay(39);  //0.4 / 10 = 0.04
//	}
//}

/*
 * @brief 获取随机障碍物
 * @author Perdixky
 */
char Abstacles_Get()
{
	srand((unsigned)HAL_GetTick());
	if (rand() % 3000 < Score) return BIG_TREE;
	if (rand() % 3000 < Score / 5) return BIRD;
	return SMALL_TREE;
}

/*
 * @brief 获取与下一个障碍物之间的间距
 * @author Perdixky
 *
 * @note 范围为42 ~ 141
 */
char Interval_Get()
{
	srand((unsigned)HAL_GetTick());
	return 42 + rand() % 100;
}

/*
 * @brief 获取获取鸟的高度
 * @author Perdixky
 *
 * @note 范围为20 ~ 35
 */
char Bird_Hight_Get()
{
	srand((unsigned)HAL_GetTick());
	return 20 + rand() % 15;
}

bool if_Collapsed()
{
	if()
}



/*
 * @brief 显示Logo
 * @author Perdixky
 */
void Show_Logo(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
{
	OLED_PrintASCIIString(64, 0, "T-Rex", &afont16x8, OLED_COLOR_NORMAL);
	OLED_PrintASCIIString(60, 16, "Chrome", &afont16x8, OLED_COLOR_NORMAL);
	OLED_PrintASCIIString(68, 32, "Dino", &afont16x8, OLED_COLOR_NORMAL);
	OLED_PrintASCIIString(68, 48, "Game", &afont16x8, OLED_COLOR_NORMAL);
	OLED_DrawImage(2, 40, &dino_front_legImg, OLED_COLOR_NORMAL);
	OLED_ShowFrame();
	while(Key_DataBuffer == 0){ }
	Key_DataBuffer = 0;
}

/*
 * @brief 显示提示
 * @author Perdixky
 */
void Show_Prompt(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
{
//	if (*(short *)FLASH_ADDRESS == 1) return;
//	*(short *)FLASH_ADDRESS = 1;
	OLED_NewFrame();
	OLED_ShowFrame();
	OLED_DrawImage(2, 40, &dino_front_legImg, OLED_COLOR_NORMAL);
	OLED_DrawImage(58, 49, &tree_smallImg, OLED_COLOR_NORMAL);
	OLED_DrawImage(88, 40, &tree_bigImg, OLED_COLOR_NORMAL);
	while(Key_DataBuffer == 0)
	{
		OLED_PrintRollingASCIIString(0, "Control your little dinosaur and void cactus!", &afont16x8, OLED_COLOR_NORMAL);
		OLED_ShowFrame();
	}
	Key_DataBuffer = 0;
}

/*
 * @brief 显示开场动画
 * @author Perdixky
 */
void Openning_Animation(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
{
	OLED_NewFrame();
	OLED_DrawImage(2, 40, &dino_front_legImg, OLED_COLOR_NORMAL);
	for(unsigned char x = 0; x < 128; x++)
	{
		OLED_SendCmd(0x81);
		OLED_SendCmd(x * 2);
		OLED_SetPixel(x, 63, OLED_COLOR_NORMAL);
		OLED_ShowFrame();
	}
}


void Dino_Game(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
//我们采用帧的方法来构建代码，即按帧检测按键，碰撞，位置等等信息，并按帧构图回应
{
	Show_Logo(GPIOx, GPIO_Pin);
	Show_Prompt(GPIOx, GPIO_Pin);
	Openning_Animation(GPIOx, GPIO_Pin);

	while(Dinosaur_state != Collapesed)
	{
		if(Dinosaur_state == Jumping)
		{
			if(if_Collapsed() == ture)
			{

			}
		}
		else if(Key_DataBuffer == 1)
		{

		}
	}


}

