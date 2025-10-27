#pragma once
#include "Mathmatics.h"
#include "Player_adventure.h"

class Enemies_adventure
{
	float enemyDmg;
	float enemySize;
	float enemyWeight = enemySize * 3;
	float enemyAttackForce = enemyDmg +
		float javelinThrower();

	float enemyInfantry();

	float enemyHeavy();

	float enemyChevalier();

	float enemyMiniBoss();

	float darkLord();
};
