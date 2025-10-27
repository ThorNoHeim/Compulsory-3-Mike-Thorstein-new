#pragma once
#include "Mathmatics.h"

class Player_adventure
{
public:
	Mathmatics position;
	float playerSpeed = 300.f;
	float playerSize = 20.f;
	float playerWeight = playerSize * 2.5f;
	float playerArmor = 30.f;
	int playerMaxHP = 200;
	int playerHP = playerMaxHP;

	void Move();

	void Draw(Mathmatics aimDirection);

	Mathmatics aimDirection();
};
