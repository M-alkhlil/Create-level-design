#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "cprocessing.h"

/// Enum for the splash screen states.
typedef enum {
    DIGIPENLOGO,     // State for displaying the DigiPen logo
    SPLASH_SCREEN    // State for displaying the studio logo
} SplashScreenState;

/// Initializes the splash screen state.
void InitializeSplashScreen(void);

/// Updates the splash screen state, handling transitions between logos and the main menu.
void UpdateSplashScreen(void);

/// Cleans up resources used by the splash screen (e.g., freeing images).
void ExitSplashScreen(void);

#endif // SPLASHSCREEN_H
