#pragma once
#include "Mathmatics.h"

class Player_adventure
{
public:
	Mathmatics position;
	int playerMaxHP = 200;
	int playerHP = playerMaxHP;
	int playerMaxStamina = 100;
	int playerStamina = playerMaxStamina;

	float playerSpeed = 300.f;
	float playerSize = 20.f;

	float playerWeight = playerSize * 2.5f;
	float playerArmor = 30.f;
	float playerArmorWeight = playerArmor * 1.5;

	float playerSprintAcceleration = 50 * GetFrameTime();
	float playerMaxSpeed = 500.f;

	float knockbackResistance(playerWeight, playerArmorWeight);

	void Move();

	void Draw(Mathmatics aimDirection);

	Mathmatics aimDirection();
};
