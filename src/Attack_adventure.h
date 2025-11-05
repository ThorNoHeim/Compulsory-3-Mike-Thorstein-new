#pragma once
#include "Player_adventure.h"
#include "Enemies_adventure.h"

class Attack_adventure : public Enemies_adventure, Player_adventure
{
public:
	int attackState = 0;

	int switchAttackState()
	{
		if (IsKeyPressed(KEY_Q))
		{
			attackState++;

			if (attackState == 3)
				attackState = 0;
		};
		return attackState;
	}

	Mathmatics position;
	Mathmatics velocity;
	bool isAlive{ false };

	float projectileDamage(float projectilVelocity);

	void Shoot(Mathmatics inStart, Mathmatics inDirection, float speed);

	void Update();

	void Draw();

	float playerKnockback = (enemyAttackForce-Player_adventure.playerKBRes)/2;

	float playerAttacks();
};
