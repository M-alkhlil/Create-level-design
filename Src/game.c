#include "game.h"
#include "player.h"

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
}

void UpdateGame(void) {
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    // Update game logic
    float deltaTime = CP_System_GetDt();
    Player_Update(&player, deltaTime);

    // Draw background centered in the screen
    float backgroundX = SCREEN_WIDTH / 2.0f;  // Center X
    float backgroundY = SCREEN_HEIGHT / 2.0f; // Center Y

    CP_Image_Draw(background, backgroundX, backgroundY, SCREEN_WIDTH, SCREEN_HEIGHT, 255);

    // Draw player
    Player_Draw(&player);
}

void ExitGame(void) {
    CP_Image_Free(&background);
    for (int i = 0; i < FRAME_COUNT; i++) {
        CP_Image_Free(&player.frames[i]);
    }
}
