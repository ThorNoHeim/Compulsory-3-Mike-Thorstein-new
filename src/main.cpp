#include <raylib.h>
#include "Mathmatics.h"
#include "Mainscreen_and_controls.h"
#include "Attack_adventure.h"
#include "Attacks_tank.h"
#include "Enemies_adventure.h"
#include "Enemies_tank.h"
#include "Environments_adventure.h"
#include "Environments_tank.h"
#include "Player_adventure.h"
#include "Player_tank.h"

int main()
{
	//screen setup
	int screenWidth = 2500;
	int screenHeight = 1300;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	//Player setup
	Player_adventure player;

	InitWindow(screenWidth, screenHeight, "Compulsory 3");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}