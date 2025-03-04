#include "cprocessing.h"
#include "splashscreen.h"
#include "mainmenu.h"
#include "game.h"  // Ensure StartGame() is defined properly
#include <stdbool.h>
#include <stdlib.h> // For rand()

// Cached variables
static CP_Image g_digipenLogo = NULL;
static CP_Image Splash_screen = NULL;
static CP_Image menuBackground = NULL;
static CP_Sound menuMusic; // Add sound variable


// Button dimensions and positions
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 40

// Button states
typedef enum {
    BUTTON_START,
    BUTTON_OPTIONS,
    BUTTON_EXIT
} ButtonType;

// Function prototypes
void DrawButton(float x, float y, const char* text);

// Splash screen state
enum SplashScreenState g_splashScreenState = DIGIPENLOGO;

// Splash Screen Functions
void InitializeSplashScreen(void)
{
    g_digipenLogo = CP_Image_Load("Assets/DigiPen_BLACK.png");
    Splash_screen = CP_Image_Load("Assets/splash-screen.png");
    menuMusic = CP_Sound_Load("Assets/menu-music.mp3");
  //  CP_Sound_Play(menuMusic, 1.0f, 1.0f, CP_SOUND_LOOP);
}

void UpdateSplashScreen(void)
{
    if (CP_Input_KeyTriggered(KEY_ANY) || CP_Input_MouseTriggered(MOUSE_BUTTON_1))
    {
        g_splashScreenState++;
    }

    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    switch (g_splashScreenState)
    {
    case DIGIPENLOGO:
        CP_Image_Draw(g_digipenLogo, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 762.5f, 222.5f, 255);
        break;
    case SPLASH_SCREEN:
        CP_Image_Draw(Splash_screen, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 512.f, 512.f, 255);
        break;
    default:
        CP_Engine_SetNextGameState(InitializeMainMenu, UpdateMainMenu, ExitMainMenu);
        break;
    }
}

void ExitSplashScreen(void)
{
    CP_Image_Free(&g_digipenLogo);
    CP_Image_Free(&Splash_screen);
}

// Main Menu Functions
void InitializeMainMenu(void)
{
    menuBackground = CP_Image_Load("Assets/Background_Menu_NoClouds.png");
}

void UpdateMainMenu(void)
{
    CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));

    if (menuBackground != NULL) {
        CP_Image_Draw(menuBackground, CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, CP_System_GetWindowWidth(), CP_System_GetWindowHeight(), 255);
    }

    float centerX = CP_System_GetWindowWidth() / 2.0f;
    float startY = CP_System_GetWindowHeight() / 2.0f - (BUTTON_HEIGHT + BUTTON_PADDING) * 1.5f;

    DrawButton(centerX - BUTTON_WIDTH / 2, startY, "Start Game");
    DrawButton(centerX - BUTTON_WIDTH / 2, startY + BUTTON_HEIGHT + BUTTON_PADDING, "Options");
    DrawButton(centerX - BUTTON_WIDTH / 2, startY + 2 * (BUTTON_HEIGHT + BUTTON_PADDING), "Exit");

    if (CP_Input_MouseClicked()) 
    {
        float mouseX = CP_Input_GetMouseX();
        float mouseY = CP_Input_GetMouseY();

        if (mouseX >= centerX - BUTTON_WIDTH / 2 && mouseX <= centerX + BUTTON_WIDTH / 2) {
            if (mouseY >= startY && mouseY <= startY + BUTTON_HEIGHT) {
               // CP_Sound_Stop(menuMusic);  // Stop the music when the game starts
                StartGame();
            }
            else if (mouseY >= startY + BUTTON_HEIGHT + BUTTON_PADDING && mouseY <= startY + 2 * BUTTON_HEIGHT + BUTTON_PADDING) {
                // Handle Options Button
            }
            else if (mouseY >= startY + 2 * (BUTTON_HEIGHT + BUTTON_PADDING) && mouseY <= startY + 3 * BUTTON_HEIGHT + 2 * BUTTON_PADDING) {
                CP_Engine_Terminate(); // Exit the game
            }
        }
    }
}

void ExitMainMenu(void)
{
    CP_Image_Free(&menuBackground);
    CP_Sound_Free(&menuMusic);  // Free sound memory

}

// Helper function to draw a button
void DrawButton(float x, float y, const char* text)
{
    CP_Settings_Fill(CP_Color_Create(100, 100, 100, 255));
    CP_Graphics_DrawRect(x, y, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
    CP_Font_DrawText(text, x + BUTTON_WIDTH / 2 - strlen(text) * 4, y + BUTTON_HEIGHT / 2);
}
