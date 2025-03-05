#include "game.h"
#include "player.h"
#include "level.h"


// Global Variables
CP_Image background;
Player player;

// Function to switch to the game state
void StartGame(void) {
    CP_Engine_SetNextGameState(InitializeGame, UpdateGame, ExitGame);
}

void InitializeGame(void) {
    CP_System_SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    CP_System_SetFrameRate(60);
    background = CP_Image_Load("Assets/background.png");
    Player_Init(&player);
    InitializeLevel();  // Load level assets

}


void UpdateGame(void) {
    // Clear screen first
    CP_Graphics_ClearBackground(CP_Color_Create(100, 150, 255, 255)); // Light blue background

    // Draw background image
    float backgroundX = SCREEN_WIDTH / 2.0f;
    float backgroundY = SCREEN_HEIGHT / 2.0f;
    CP_Image_Draw(background, backgroundX, backgroundY, SCREEN_WIDTH, SCREEN_HEIGHT, 255);

    // Draw level blocks
    DrawLevel();

    // Update player movement
    float deltaTime = CP_System_GetDt();
    Player_Update(&player, deltaTime);

    // Draw player
    Player_Draw(&player);
}


void ExitGame(void) {
    // Free background image
    CP_Image_Free(background);

    // Free player animation frames
    for (int i = 0; i < FRAME_COUNT; i++) {
        CP_Image_Free(player.frames[i]);
    }

    // Free level resources
 }

