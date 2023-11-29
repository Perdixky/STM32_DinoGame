/*
 * OLED.h
 *
 *  Created on: Nov 24, 2023
 *      Author: 32937
 */

#ifndef OLED_H_
#define OLED_H_

#include "OLED_Font.h"
#include "i2c.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// I2C句柄
#define OLED_HANDLE           &hi2c1

// OLED器件地址
#define OLED_ADDRESS          0x78

// OLED参数
#define OLED_PAGE              8                // OLED页数
#define OLED_ROW         8 * OLED_PAGE          // OLED行数
#define                 OLED_COLUMN 128         // OLED列数



typedef enum {
  OLED_COLOR_NORMAL = 0, // 正常模式 黑底白字
  OLED_COLOR_REVERSED    // 反色模式 白底黑字
} OLED_ColorMode;

void OLED_SendCmd(uint8_t cmd);

void OLED_Init();
void OLED_DisPlay_On();
void OLED_DisPlay_Off();

void OLED_NewFrame();
void OLED_ShowFrame();
void OLED_SetPixel(uint8_t x, uint8_t y, OLED_ColorMode color);

void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_ColorMode color);
void OLED_DrawRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
void OLED_DrawFilledRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
void OLED_DrawFilledCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);
void OLED_DrawImage(uint8_t x, uint8_t y, const Image *img, OLED_ColorMode color);

void OLED_PrintASCIIChar(uint8_t x, uint8_t y, char ch, const ASCIIFont *font, OLED_ColorMode color);
void OLED_PrintASCIIString(uint8_t x, uint8_t y, char *str, const ASCIIFont *font, OLED_ColorMode color);
void OLED_PrintString(uint8_t x, uint8_t y, char *str, const Font *font, OLED_ColorMode color);

void OLED_PrintRollingASCIIString(uint8_t y, char* str, const ASCIIFont* font, OLED_ColorMode color);


#endif /* OLED_H_ */
