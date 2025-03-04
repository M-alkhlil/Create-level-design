#include "block.h"

Block blocks[BLOCK_COUNT];
CP_Image blockImage;

void Blocks_Init(void) {
    blockImage = CP_Image_Load("Assets/Tileset.png");

    // Define block positions (Modify as needed)
    blocks[0] = (Block){ 150, 400, 50, 50 };
    blocks[1] = (Block){ 300, 350, 50, 50 };
    blocks[2] = (Block){ 450, 300, 50, 50 };
    blocks[3] = (Block){ 600, 250, 50, 50 };
    blocks[4] = (Block){ 750, 200, 50, 50 };
}

void Blocks_Draw(void) {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        CP_Image_Draw(blockImage, blocks[i].x, blocks[i].y, blocks[i].width, blocks[i].height, 255);
    }
}

// Check if player is standing on a block
int Check_Collision(float playerX, float playerY, float playerWidth, float playerHeight) {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        Block b = blocks[i];

        // Check collision with top of the block
        if (playerX + playerWidth > b.x && playerX < b.x + b.width &&   // Horizontal overlap
            playerY + playerHeight >= b.y && playerY + playerHeight <= b.y + 5) { // Vertical collision
            return 1; // Collision detected
        }
    }
    return 0; // No collision
}
