#pragma once
#include "Mathmatics.h"

class Player_adventure
{
public:
	Mathmatics position;

	float speed = 500.f;
	float size = 25.f;

	void Move();
	void Draw(Mathmatics aimDirection);
	Mathmatics aimDirection();
};
