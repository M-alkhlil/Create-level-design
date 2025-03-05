#include "level.h"

CP_Image tileImage;  // Image for the tiles
Block blocks[NUM_BLOCKS];  // Array to store all block positions

// **First Row Initialization**
void InitializeFirstRow(void) {
    float startX = 30;  // Leftmost position
    float startY = 955;  // Bottom row position

    for (int i = 0; i < 20; i++) {  // 10 blocks in the first row
        blocks[i].x = startX + (i * TILE_SIZE);
        blocks[i].y = startY;
    }
}

// **Second Row Initialization**
void InitializeSecondRow(void) {
    float secondRowX = 650;  // Offset to the right
    float secondRowY = 850;  // Slightly above first row

    for (int i = 0; i < 5; i++) {  // 4 blocks in the second row
        blocks[10 + i].x = secondRowX + (i * TILE_SIZE);
        blocks[10 + i].y = secondRowY;
    }
}

// **Third Row Initialization**
void InitializeThirdRow(void) {
    float thirdRowX = 450;  // Offset to the right
    float thirdRowY = 700;  // Above the second row

    for (int i = 0; i < 2; i++) {  // 3 blocks in the third row
        blocks[14 + i].x = thirdRowX + (i * TILE_SIZE);
        blocks[14 + i].y = thirdRowY;

        box.x = thirdRowX + TILE_SIZE;  // Middle block of row 3
        box.y = thirdRowY - TILE_SIZE;  // Slightly above the block
    }
}
void DrawBox(void) {
    CP_Image boxImage = CP_Image_Load("Assets/box1.png");  // Load box sprite
    CP_Image_Draw(boxImage, box.x, box.y, Box_SIZE, Box_SIZE, 255);
}

// *Initialize the Entire Level**
void InitializeLevel(void) {
    tileImage = CP_Image_Load("Assets/11.png"); // Load block image

    // Call each row initialization function
    InitializeFirstRow();
    InitializeSecondRow();
    InitializeThirdRow();
}

// 🟢 **Draw the First Row**
void DrawFirstRow(void) {
    for (int i = 0; i < 10; i++) {
        CP_Image_Draw(tileImage, blocks[i].x, blocks[i].y, TILE_SIZE, TILE_SIZE, 255);
    }
}

// 🟡 **Draw the Second Row**
void DrawSecondRow(void) {
    for (int i = 10; i < 14; i++) {
        CP_Image_Draw(tileImage, blocks[i].x, blocks[i].y, TILE_SIZE, TILE_SIZE, 255);
    }
}

// 🔴 **Draw the Third Row**
void DrawThirdRow(void) {
    for (int i = 14; i < 17; i++) {
        CP_Image_Draw(tileImage, blocks[i].x, blocks[i].y, TILE_SIZE, TILE_SIZE, 255);

    }
}

// ✅ **Draw the Entire Level**
void DrawLevel(void) {
    DrawFirstRow();
    DrawSecondRow();
    DrawThirdRow();
    DrawBox();  // Draw the box on row 3

}

// ✅ **Clean up the Level**
void Level_Exit(void) {
    CP_Image_Free(tileImage);
}
