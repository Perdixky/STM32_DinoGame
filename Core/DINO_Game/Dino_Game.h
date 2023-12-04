/*
 * Dino_Game.h
 *
 *  Created on: Nov 25, 2023
 *      Author: 32937
 */

#ifndef DINO_GAME_DINO_GAME_H_
#define DINO_GAME_DINO_GAME_H_




#define FLASH_ADDRESS
//闪存地址，用于储存最佳分数和是否显示提示


#include "OLED.h"
#include "main.h"
#include "tim.h"
#include "Key.h"
#include "gpio.h"
#include "Dino_Image&Font.h"
#include "stdio.h"


constexpr enum Obstacle_State{
	Exist = 1,
	Unexist = 0
};

constexpr enum Dino_State{
	Running = 0,
	Jumping,
	Bending,
	Collapesed
};


class Obstacle{
public:
	Obstacle() = default;
	static void Move();
	void Appear();
private:
	Image type { tree_bigImg }; //障碍物类型
	bool status { Unexist }; //是否在屏幕中
	char x { 127 }; //横坐标
	char y { 0 }; //纵坐标
	char wing { 0 };//如果是鸟，鸟的翅膀状态，0是up，1是down
};


void Dino_Game(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin);
#endif /* DINO_GAME_DINO_GAME_H_ */
