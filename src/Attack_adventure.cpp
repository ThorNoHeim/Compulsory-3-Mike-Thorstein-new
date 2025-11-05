#include "Attack_adventure.h"

float Attack_adventure::projectileDamage(float projectileVelocity)
{
	float projectileDmg = projectileVelocity * 0.5f;

	return projectileDmg;
}

void Attack_adventure::Shoot(Mathmatics inStart, Mathmatics inDirection, float speed)
{
	position = inStart;
	velocity = inDirection.vectorScalar(speed);
	isAlive = true;
}

void Attack_adventure::Update()
{
	if (isAlive)
	{
		position = position.vectorOffset(velocity.vectorScalar(GetFrameTime()));

		if (position.x < 0 || position.x > GetScreenWidth() || position.y < 0 || position.y > GetScreenHeight())
		{
			isAlive = false;
		}
	}
}

void Attack_adventure::Draw()
{
	if (isAlive)
	{
		//DrawCircle(position.x, position.y, 5.f, LIGHTGRAY);
		DrawLine(position.x, position.y, position.x, position.y, BROWN);
		//DrawRectangle(position.x, position.y, 5, 15, DARKBROWN);
	}
}

float Attack_adventure::playerAttacks()
{
	return 0.0f;
}