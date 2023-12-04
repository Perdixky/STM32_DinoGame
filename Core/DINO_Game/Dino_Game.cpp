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
 * @return Key_DataBuffer 最近一次按键状态
 *
 * @note 按键一端连接PA12（下拉输入模式），一端连接高电平
 * @note 读取Key_DataBuffer后需要手动置零
 */
volatile char Key_DataBuffer = 0;  //此数据会在中断中改变，必须使用volatile关键字
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_12)
	{
		Key_DataBuffer = Key_InputData(GPIOA, GPIO_PIN_12);
	}
}

//得分
unsigned short Score = 0;

//恐龙高度
unsigned char Dinosaur_Hight = 0;

//小恐龙状态
char Dinosaur_state = Running;

//0.8s 跳跃时长的抛物线近似值
constexpr unsigned char Jump_Hight[21] = { 40, 33, 27, 22, 17, 12, 8, 5, 3, 1, 0, 1, 3, 5,  8, 12, 17, 22, 27, 33, 40 };

//可能出现的障碍物（程序决定了屏幕中同时最多同时出现三个障碍物）
Obstacle obstacle1, obstacle2, obstacle3;

void Dino_Run()
{
	if(static_cast<bool>(Score & 1))
		OLED_DrawImage(2, 40, &dino_front_legImg, OLED_COLOR_NORMAL);
	else
		OLED_DrawImage(2, 40, &dino_back_legImg, OLED_COLOR_NORMAL);
}

bool is_odd(char x)
{
	return static_cast<bool> (x | 1);
}

/*
 * @brief 恐龙跳跃
 * @author Perdixky
 *
 * @note 使用static的x来实现每次调用该函数时自动变换位置
 */
void Dino_Jump()
{
	static char x{ 0 };
	if (is_odd(Score)) x++;
	Dinosaur_Hight = Jump_Hight[x];
	OLED_DrawImage(2, Jump_Hight[x], &dino_jumpsImg, OLED_COLOR_NORMAL);
}


/*
 * @brief 获取与下一个障碍物之间的间距
 * @author Perdixky
 *
 * @note 范围为58 ~ 158
 */
char Interval_Get()
{
	srand((unsigned)HAL_GetTick());
	return 63 + rand() % 100;
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
/*
 * @brief 判断是否碰撞
 * @author Perdixky
 *
 * @return 碰撞返回true，反之false
 */
bool is_Collapsed()
{
	return obstacle1.status && obstacle1.x <= 23 && obstacle1.x >= 2 && !(obstacle1.y <= Dinosaur_Hight + 23 || obstacle1.y + obstacle1.type.h <= Dinosaur_Hight)
			|| obstacle2.status && obstacle2.x <= 23 && obstacle1.x >= 2 && !(obstacle2.y <= Dinosaur_Hight + 23 || obstacle2.y + obstacle2.type.h <= Dinosaur_Hight)
			|| obstacle3.status && obstacle3.x <= 23 && obstacle1.x >= 2 && !(obstacle3.y <= Dinosaur_Hight + 23 || obstacle3.y + obstacle3.type.h <= Dinosaur_Hight);
}

/*
 * @brief 读取，判断，储存成绩
 * @author Perdixky
 *
 */
void Score_process()
{

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

/*
 * @brief 出现随机障碍物
 * @author Perdixky
 *
 * @note 随着分数的增大出现大树和鸟的几率增大
 */
void Obstacle::Appear()
{
	srand((unsigned)HAL_GetTick());
	if (rand() % 3000 < Score / 5)
	{
		y = Bird_Hight_Get();
		if(!obstacle1.status)
		{
			obstacle1.type = bird_wing_upImg;
			obstacle1.y = y;
			obstacle1.status = Exist;
		}
		else if(!obstacle2.status)
		{
			obstacle2.type = bird_wing_upImg;
			obstacle2.status = Exist;
		}
		else
		{
			obstacle3.type = bird_wing_upImg;
			obstacle3.status = Exist;
		}
		OLED_DrawImage(128, y, bird_wing_upImg, OLED_COLOR_NORMAL);
	}
	else if (rand() % 3000 < Score)
	{
		if(!obstacle1.status)
		{
			obstacle1.type = tree_bigImg;
			obstacle1.y = 40;
			obstacle1.status = Exist;
		}
		else if(!obstacle2.status)
		{
			obstacle2.type = tree_bigImg;
			obstacle1.y = 40;
			obstacle2.status = Exist;
		}
		else
		{
			obstacle3.type = tree_bigImg;
			obstacle1.y = 40;
			obstacle3.status = Exist;
		}
		OLED_DrawImage(128, 40, tree_bigImg, OLED_COLOR_NORMAL);
	}
	else
	{
		if(!obstacle1.status)
		{
			obstacle1.type = tree_samllImg;
			obstacle1.y = 49;
			obstacle1.status = Exist;
		}
		else if(!obstacle2.status)
		{
			obstacle2.type = tree_samllImg;
			obstacle1.y = 49;
			obstacle2.status = Exist;
		}
		else
		{
			obstacle3.type = tree_samllImg;
			obstacle1.y = 49;
			obstacle3.status = Exist;
		}
		OLED_DrawImage(128, 49, tree_samllImg, OLED_COLOR_NORMAL);
	}
}

/*
 * @brief 障碍物向左移动一个单位长度（默认树为全局变量）
 * @author Perdixky
 *
 * @note 只需使用Obstacle.Move()即可实现移动
 */
void Obstacle::Move()
{
	if(status)
	{
		x --;
		if(x < -type.w)
		{
			status = Unexist;
			return;
		}
		OLED_DrawImage(x, 41, tree_bigImg, OLED_COLOR_NORMAL);
		break;
		if(type == bird_wing_downImg)
		{
			if(this->x % 4 == 0)       //每位移四个单位长度就将翅膀状况取反
				type == bird_wing_upData;
		}//这里的大括号是必须的，保证else与第一个if匹配
		else if(type == bird_wing_downImg)
		{
			if(this->x % 4 == 0)       //每位移四个单位长度就将翅膀状况取反
				type == bird_wing_upData;
		}
	}
	return;
}

/*
 * @brief 游戏主函数
 * @author Perdixky
 *
 * @note 一帧20ms，使用定时器中断回调函数来实现，优先级低于外部中断
 */
void Dino_Game(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin)
//我们采用帧的方法来构建代码，即按帧检测按键，碰撞，位置等等信息，并按帧构图回应
//可以有效的进行碰撞检测，显存更新，而且不用频繁使用I2C通信
{
	Show_Logo(GPIOx, GPIO_Pin);
	Show_Prompt(GPIOx, GPIO_Pin);
	Openning_Animation(GPIOx, GPIO_Pin);
	char num[5];
	memset(num, 0x00, 5);//初始化
	while(true)
	{
		OLED_NewFrame(); //每一次循环都清除上一个显存数据
		OLED_PrintASCIIString(40, 2, "Score:", afont12x6, OLED_COLOR_NORMAL);
		snprintf(num, 6, "%d", score);
		OLED_PrintASCIIString(40, 2, "Score:", afont12x6, OLED_COLOR_NORMAL);
		if(static_cast<bool> (Key_DataBuffer)) Dinosaur_state = Jumping; //跳跃中再按也不会发生变化
		if (Dinosaur_state == Jumping) Dino_Jump();
		for(char x = Interval_Get(); x > 0; x--)
		{
			Score ++;
			obstacle1.Move();
			obstacle2.Move();
			obstacle3.Move();
		}
		if(is_Collapsed())
		{
			break;
		}
		Obstacle::Appear();
		OLED_ShowFrame();
	}
}

