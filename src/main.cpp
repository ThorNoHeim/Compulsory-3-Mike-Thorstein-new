#include <raylib.h>
#include "Mathmatics.h"

int main()
{
	int screenWidth = 2550;
	int screenHeight = 1450;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

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