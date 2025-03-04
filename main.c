#include "cprocessing.h"
#include "game.h"
#include "cprocessing.h"
#include "splashscreen.h"
#include "mainmenu.h"
 




void main(void) {
	//CP_Engine_SetNextGameState(InitializeGame, UpdateGame, ExitGame);
	CP_System_SetWindowSize(800, 600); // Set window size

	CP_Engine_SetNextGameState(InitializeSplashScreen, UpdateSplashScreen, ExitSplashScreen);



	CP_Engine_Run();
}