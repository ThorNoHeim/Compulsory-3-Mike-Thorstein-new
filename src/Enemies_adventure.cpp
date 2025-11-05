#include "Enemies_adventure.h"

void Enemies_adventure::Spawn(int inScreenWidth, int inScreenHeight)
{
	int margin = 40;

	position = {
	(float)(margin + rand() % (inScreenWidth - 2 * margin)),
	(float)(margin + rand() % (inScreenHeight - 2 * margin))
	};

	forwardVector =
	{
		(rand() % 2 == 0 ? 1.f : -1.f),
		(rand() % 2 == 0 ? 1.f : -1.f)
	};

	isDetected = false;
}

void Enemies_adventure::Update(Mathmatics inTargetPosition)
{
	if (isAlive)
	{
		// Direction to player
		Mathmatics toPlayer = position.vectorTowardTarget(inTargetPosition);
		float distanceToPlayer = toPlayer.getPythagoras();
		//std::cout << distanceToPlayer << "\n";
		std::cout << inTargetPosition.x << " | " << inTargetPosition.y << "\n";

		// Normalize
		Mathmatics toPlayerDirection = toPlayer.NormalizeVector();

		// Angle between vectors
		float angleToPlayer = forwardVector.angleBetweenVectors(toPlayerDirection);

		// Check FOV and Distance
		if (distanceToPlayer < detectionRange && angleToPlayer < fovAngle)
		{
			isDetected = true;
		}
		else
		{
			isDetected = false;
		}

		// Detected AI Behaviour
		if (isDetected)
		{
			// Determine which direction to turn
			float crossProduct = forwardVector.CrossProduct(toPlayerDirection);
			float dotProduct = forwardVector.DotProduct(toPlayerDirection);

			// Rotate towards player
			float rotationAmount = rotationSpeed * GetFrameTime();
			if (crossProduct > 0)
			{
				rotationAmount = -rotationAmount;
			}

			// Apply rotation
			if (fabsf(crossProduct) > 0.01f)
			{
				// Calculate facing angle
				float angle = atan2f(forwardVector.y, forwardVector.x);
				angle -= rotationAmount;
				forwardVector.x = cosf(angle);
				forwardVector.y = sinf(angle);
			}

			// Chasing player
			forwardVector = toPlayerDirection;
			position = position.vectorOffset(forwardVector.vectorScalar(speed * GetFrameTime()));

			if (distanceToPlayer < 30.f)
			{
				Spawn(GetScreenWidth(), GetScreenHeight());
			}
		}
		// Patrol AI Behaviour
		else
		{
			position = position.vectorOffset(forwardVector.vectorScalar(speed * GetFrameTime()));

			if (position.x < 50 || position.x > GetScreenWidth() - 50)
			{
				forwardVector.x *= -1;
			}
			if (position.y < 50 || position.y > GetScreenHeight() - 50)
			{
				forwardVector.y *= -1;
			}
		}
	}
}

void Enemies_adventure::Draw()
{
	if (isAlive)
	{
		Color color = isDetected ? RED : GREEN;
		DrawCircle(position.x, position.y, enemySize, color);

		Mathmatics lineEnd = position.vectorOffset(forwardVector.vectorScalar(25.f));

		// --- FOV Visualization ---
		float halfFOV = fovAngle * 0.5f * (PI / 180.f);

		Mathmatics leftBound{
			cosf(atan2f(forwardVector.y, forwardVector.x) - halfFOV),
			sinf(atan2f(forwardVector.y, forwardVector.x) - halfFOV)
		};
		Mathmatics rightBound{
			cosf(atan2f(forwardVector.y, forwardVector.x) + halfFOV),
			sinf(atan2f(forwardVector.y, forwardVector.x) + halfFOV)
		};

		Mathmatics leftEnd = position.vectorOffset(leftBound.vectorScalar(detectionRange));
		Mathmatics rightEnd = position.vectorOffset(rightBound.vectorScalar(detectionRange));

		DrawLineV({ position.x, position.y }, { leftEnd.x, leftEnd.y }, Fade(RED, 1.f));
		DrawLineV({ position.x, position.y }, { rightEnd.x, rightEnd.y }, Fade(RED, 1.f));
	}
}

float Enemies_adventure::javelinThrower()
{
	return 0.0f;
}

float Enemies_adventure::enemyInfantry()
{
	return 0.0f;
}

float Enemies_adventure::enemyHeavy()
{
	return 0.0f;
}

float Enemies_adventure::enemyChevalier()
{
	return 0.0f;
}

float Enemies_adventure::enemyMiniBoss()
{
	return 0.0f;
}

float Enemies_adventure::darkLord()
{
	return 0.0f;
}