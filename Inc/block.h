#ifndef BLOCK_H
#define BLOCK_H

#include "cprocessing.h"

typedef struct {
    float x, y;
    float width, height;
} Block;

#define BLOCK_COUNT 5

void Blocks_Init(void);
void Blocks_Draw(void);
int Check_Collision(float playerX, float playerY, float playerWidth, float playerHeight);

#endif
