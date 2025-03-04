#include "player.h"
#include "game.h"


void Player_Init(Player* player) {
	player->frames[0] = CP_Image_Load("Assets/player1.png");
	player->frames[1] = CP_Image_Load("Assets/player2.png");
	player->frames[2] = CP_Image_Load("Assets/player3.png");
	player->frames[3] = CP_Image_Load("Assets/player4.png");
	player->frames[4] = CP_Image_Load("Assets/player5.png");
	player->x = SCREEN_WIDTH / 2.0f - 85 / 2.0f;
	player->y = SCREEN_HEIGHT - 118 - 5; // Ground level
	player->frameTimer = 0.0f;
	player->currentFrame = 0;
	player->isMovingRight = 0;
	player->facingRight = 1;
	player->velocityY = 0.0f;
	player->isJumping = 0;
}
void Player_Update(Player* player, float deltaTime) {
	player->isMovingRight = 0;
	// Move Right
	if (CP_Input_KeyDown(KEY_D)) {
		player->x += PLAYER_SPEED * deltaTime;
		player->isMovingRight = 1;
		player->facingRight = 1;
	}
	// Move Left
	if (CP_Input_KeyDown(KEY_A)) {
		player->x -= PLAYER_SPEED * deltaTime;
		player->isMovingRight = 1;
		player->facingRight = 0;
	}
	// Jumping
	if (CP_Input_KeyTriggered(KEY_SPACE) && player->isJumping == 0) {
		player->velocityY = JUMP_FORCE;
		player->isJumping = 1;
	}
	// Apply gravity
	player->velocityY += GRAVITY * deltaTime;
	player->y += player->velocityY * deltaTime;
	// Collision with ground
	if (player->y >= SCREEN_HEIGHT - 118 - 5) {
		player->y = SCREEN_HEIGHT - 118 - 5;
		player->velocityY = 0;
		player->isJumping = 0;
	}
	// Update animation
	if (player->isMovingRight) {
		player->frameTimer += deltaTime;
		if (player->frameTimer >= FRAME_TIME) {
			player->frameTimer = 0.0f;
			player->currentFrame = (player->currentFrame + 1) % FRAME_COUNT;
		}
	}
	else {
		player->currentFrame = 0;
	}
}void Player_Draw(Player* player) {
	CP_Image_Draw(player->frames[player->currentFrame], player->x, player->y, 50, 50, 255);
}
