/*
 * Dino_Game.h
 *
 *  Created on: Nov 25, 2023
 *      Author: 32937
 */

#ifndef DINO_GAME_DINO_GAME_H_
#define DINO_GAME_DINO_GAME_H_


#define FLASH_ADDRESS            0x08000000
//闪存地址，用于储存最佳分数和是否显示提示

class Tree{
public:
	Tree() = default;
	char type;
	char x;
}


enum Obstacle_State{
	Exist = 0,
	Unexist
};

enum Dino_State{
	Running = 0,
	Jumping,
	Bending,
	Collapesed
};

enum Obstacles{
	SMALL_TREE = 0,
	BIG_TREE,
	BIRD
};

#include "OLED.h"
#include "main.h"
#include "tim.h"
#include "Key.h"
#include "gpio.h"
#include "Dino_Image&Font.h"

void Dino_Game(GPIO_TypeDef* GPIOx, unsigned short GPIO_Pin);
#endif /* DINO_GAME_DINO_GAME_H_ */
