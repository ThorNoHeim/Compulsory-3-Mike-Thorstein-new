#pragma once
#include "Mathmatics.h"
#include "Player_adventure.h"

class Enemies_adventure
{
public:

	Mathmatics position;
	Mathmatics forwardVector{ 1, 0 };
	float speed = 200.f;
	float enemySize = 30.f;
	float detectionRange = 300.f;
	float fovAngle = 60.f;
	float rotationSpeed = 0.01f; // Radian/sec
	bool isAlive{ true };
	bool isDetected{ false };

	float enemyDmg;
	float enemyWeight = enemySize * 3;
	float enemyKnockback;
	float enemyAttackForce = enemyDmg + enemyKnockback;

	void Spawn(int inScreenWidth, int inScreenHeight);

	void Update(Mathmatics inTargetPosition);

	void Draw();

	float javelinThrower();

	float enemyInfantry();

	float enemyHeavy();

	float enemyChevalier();

	float enemyMiniBoss();

	float darkLord();
};
