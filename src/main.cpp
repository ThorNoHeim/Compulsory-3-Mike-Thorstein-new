#include <raylib.h>
#include <iostream>

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
	int screenWidth = 2550;
	int screenHeight = 1450;

	float halfScreenWidth = (float)(screenWidth / 2);
	float halfScreenHeight = (float)(screenHeight / 2);

	// Player Setup
	Player_adventure player;
	player.position = { halfScreenWidth, halfScreenHeight };

	// Player arrow Setup
	int amountOfArrows = 10;
	std::vector<Attack_adventure> arrowContainer(amountOfArrows);

	// Enemy Setup
	int amountOfEnemies = 10;
	std::vector<Enemies_adventure> enemyContainer(amountOfEnemies);

	for (Enemies_adventure& enemyInstance : enemyContainer)
	{
		enemyInstance.Spawn(screenWidth, screenHeight);
	}

	InitWindow(screenWidth, screenHeight, "Compulsory 3");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Update
		player.Move();
		Mathmatics aimDirection = player.aimDirection();
		for (Enemies_adventure& enemyObject : enemyContainer)
		{
			enemyObject.Update(player.position);
		}

		// Shoot bullets
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			for (Attack_adventure& arrow : arrowContainer)
			{
				if (arrow.isAlive == false)
				{
					arrow.Shoot(player.position, aimDirection, 2000.f);
					break;
				}
			}
		}

		for (Attack_adventure& bulletObject : arrowContainer)
		{
			bulletObject.Update();
		}

		// Check collision between Bullet and Enemy

		for (Attack_adventure& arrow : arrowContainer)
		{
			if (arrow.isAlive)
			{
				for (Enemies_adventure& enemy : enemyContainer)
				{
					if (arrow.position.targetDistance(enemy.position) < enemy.enemySize && enemy.isAlive)
					{
						enemy.Spawn(screenWidth, screenHeight);
						arrow.isAlive = false;
					}
				}
			}
		}

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);

		player.Draw(aimDirection);

		for (Enemies_adventure& enemy : enemyContainer)
		{
			enemy.Draw();
		}
		for (Attack_adventure& bullet : arrowContainer)
		{
			bullet.Draw();
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}