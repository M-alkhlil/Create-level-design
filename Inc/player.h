#ifndef PLAYER_H
#define PLAYER_H

#include "cprocessing.h"

// Constants
#define PLAYER_SPEED 200.0f
#define JUMP_FORCE -500.0f
#define GRAVITY 980.0f
#define FRAME_COUNT 5
#define FRAME_TIME 0.1f

// Player structure
typedef struct {
    CP_Image frames[FRAME_COUNT];
    float x, y;
    float velocityY;
    int currentFrame;
    float frameTimer;
    int isMovingRight;
    int facingRight;
    int isJumping;
} Player;

// Function prototypes
void Player_Init(Player* player);
void Player_Update(Player* player, float deltaTime);
void Player_Draw(Player* player);

#endif
