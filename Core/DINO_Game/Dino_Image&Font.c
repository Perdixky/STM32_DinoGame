/*
 * Dino_Image&Font.c
 *
 *  Created on: Nov 25, 2023
 *      Author: 32937
 */

#include "Dino_Image&Font.h"

const uint8_t zh20x16[][44] = {
/* 0 T */ {0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x04,0x04,0xfc,0xfc,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 1 - */ {0x2d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 2 R */ {0x52,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0xfc,0x04,0x04,0x04,0x04,0x04,0x8c,0xf8,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x3f,0x01,0x01,0x01,0x03,0x07,0x0d,0x18,0x30,0x20,0x00,0x00,0x00,0x00,},
/* 3 e */ {0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf0,0x98,0x98,0x88,0x88,0x88,0x98,0xf0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0f,0x19,0x18,0x10,0x10,0x10,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 4 x */ {0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x18,0x30,0xe0,0xc0,0xc0,0xe0,0x30,0x18,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x0e,0x07,0x01,0x01,0x07,0x0e,0x18,0x10,0x00,0x00,0x00,0x00,0x00,},
/* 5   */ {0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 6 C */ {0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf8,0x18,0x0c,0x04,0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1f,0x18,0x30,0x20,0x20,0x20,0x20,0x20,0x20,0x30,0x00,0x00,0x00,0x00,},
/* 7 h */ {0x68,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xfe,0xc0,0x60,0x20,0x20,0x20,0x60,0xe0,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x00,0x00,0x00,0x00,0x00,},
/* 8 r */ {0x72,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0xf8,0x10,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 9 o */ {0x6f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf0,0x18,0x08,0x08,0x08,0x08,0x18,0xf0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0f,0x18,0x10,0x10,0x10,0x10,0x18,0x0f,0x07,0x00,0x00,0x00,0x00,0x00,},
/* 10 m */ {0x6d,0x00,0x00,0x00,0x00,0x00,0xf8,0xf8,0x10,0x18,0x18,0x18,0x18,0xf0,0xf0,0x10,0x18,0x18,0x18,0x18,0xf0,0xf0,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,},
/* 11 D */ {0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0xfc,0x04,0x04,0x04,0x04,0x04,0x0c,0x0c,0x18,0xf8,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x3f,0x20,0x20,0x20,0x20,0x20,0x30,0x30,0x18,0x0f,0x07,0x00,0x00,0x00,0x00,},
/* 12 i */ {0x69,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe4,0xe4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
/* 13 n */ {0x6e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0xf8,0x30,0x10,0x18,0x18,0x18,0x18,0xf0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,},
/* 14 G */ {0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf0,0x18,0x0c,0x0c,0x04,0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1f,0x18,0x30,0x20,0x20,0x20,0x21,0x21,0x21,0x3f,0x3f,0x00,0x00,0x00,0x00,},
/* 15 a */ {0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x98,0x88,0x88,0x88,0x98,0x98,0xf0,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x1b,0x10,0x10,0x10,0x18,0x08,0x0c,0x1f,0x1f,0x00,0x00,0x00,0x00,0x00,}
};
const Font font20x16 = {20, 16, (const uint8_t *)zh20x16, 16, &afont16x8};

const uint8_t dino_crashedData[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xf1, 0xf5, 0xf1, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x7f, 0xfc, 0xf8, 0xe0, 0xe0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x04, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x81, 0x83, 0x87, 0xff, 0xdf, 0x87, 0x87, 0x87, 0xff, 0xc3, 0xc3, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
};
const Image dino_crashedImg = {21, 23, dino_crashedData};
// Dino lifts front leg
const uint8_t dino_front_legData[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xbf, 0xbf, 0xbf, 0x3f, 0x3e, 0x3f, 0xfc, 0xf8, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x04, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x81, 0x83, 0x87, 0xff, 0xdf, 0x8f, 0x87, 0x87, 0x8f, 0x8b, 0x8b, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
};
const Image dino_front_legImg = {21, 23, dino_front_legData};
// Dino lifts back leg
const uint8_t dino_back_legData[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xbf, 0xbf, 0xbf, 0x3f, 0x3e, 0x3f, 0xfc, 0xf8, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x04, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x81, 0x83, 0x87, 0x8f, 0x9f, 0x97, 0x87, 0x8f, 0xff, 0xc3, 0xc3, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
};
const Image dino_back_legImg = {21, 23, dino_back_legData};
// Dino jumps
const uint8_t dino_jumpsData[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xbf, 0xbf, 0xbf, 0x3f, 0x3e, 0x3f, 0xfc, 0xf8, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x04, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x81, 0x83, 0x87, 0xff, 0xdf, 0x8f, 0x87, 0x8f, 0xff, 0xc3, 0xc3, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
};
const Image dino_jumpsImg = {21, 23, dino_jumpsData};
// Small tree
const uint8_t tree_smallData[] = {
    0xf8, 0x00, 0xff, 0xff, 0xc0, 0x7c, 0xc1, 0xc1, 0xff, 0xff, 0xc0, 0xc0,
};
const Image tree_smallImg = {6, 14, tree_smallData};
// Big tree
const uint8_t tree_bigData[] = {
    0x80, 0xc0, 0x80, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe0, 0xe0, 0xe0, 0x3f, 0x7f, 0x7f, 0x60, 0xff, 0xff, 0xff, 0xff, 0x60, 0x7f, 0x3f, 0x1f, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80,
};
const Image tree_bigImg = {12, 23, tree_bigData};
const uint8_t bird_wing_downData[] = {
0x00, 0x00, 0x10, 0x18, 0x1c, 0x1e, 0x1f, 0x1e, 0x38, 0x70, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x00, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xbf, 0x8f, 0x83, 0x83, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80,
};
const Image bird_wing_downImg = {23, 15, bird_wing_downData};
const uint8_t bird_wing_upData[] = {
0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x80, 0x00, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x81, 0x81, 0x81, 0x81, 0x83, 0x86, 0x8f, 0x9f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0xbc, 0x9c, 0x94, 0x94, 0x84, 0x80, 0x80,
};
const Image bird_wing_upImg = {22, 15, bird_wing_upData};

