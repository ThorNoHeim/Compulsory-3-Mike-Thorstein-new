#include "Enemies_tank.h"

void Enemies_tank::Respawn(int inScreenWidth, int inScreenHeight)
{
	int margin = 100;

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

void Enemies_tank::update(Vector2d inTargetPosition)
{
	if (IsAlive)
	{
		// Direction to player
		Vector2d toPlayer = position.VectorTowardsTarget(inTargetPosition);
		float distanceToPlayer = toPlayer.CalculateMagnitude();

		// Normalize
		Vector2d toPlayerDirection = toPlayer.NormalizeVector();

		// Angle between vectors
		float angleToPlayer = forwardVector.AngleBetweenVectors(toPlayerDirection);

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
			position = position.SetVectorOffset(forwardVector.ScaleVector(speed * GetFrameTime()));

			if (distanceToPlayer < 30.f)
			{
				Respawn(GetScreenWidth(), GetScreenHeight());
			}
		}
		// Patrol AI Behaviour
		else
		{
			position = position.SetVectorOffset(forwardVector.ScaleVector(speed * GetFrameTime()));

			if (position.x < 50 || position.x > GetScreenWidth() - 50)
			{
				forwardVector.x *= -1;
			}
			if (position.y < 50 || position.y > GetScreenHeight() - 50)
			{
				forwardVector.y *= -1;
			}
		}

		// Old "AI" Logic
		//Vector2d direction = position.VectorTowardsTarget(inTargetPosition).NormalizeVector();
		//position = position.SetVectorOffset(direction.ScaleVector(speed * GetFrameTime()));

		//if (position.DistanceToTarget(inTargetPosition) < 25.f)
		//{
		//	Respawn(GetScreenWidth(), GetScreenHeight());
		//}
	}
}

void Enemies_tank::Draw()
{
	if (IsAlive)
	{
		Color color = isDetected ? DARKGREEN : GREEN;
		DrawRectangle(position.x, position.y, size, size, color);

		Vector2d lineEnd = position.SetVectorOffset(forwardVector.ScaleVector(25.f));
		DrawLineV({ position.x, position.y }, { lineEnd.x, lineEnd.y }, WHITE);

		// --- FOV Visualization ---
		float halfFOV = fovAngle * 0.5f * (PI / 180.f);

		Vector2d leftBound{
			cosf(atan2f(forwardVector.y, forwardVector.x) - halfFOV),
			sinf(atan2f(forwardVector.y, forwardVector.x) - halfFOV)
		};
		Vector2d rightBound{
			cosf(atan2f(forwardVector.y, forwardVector.x) + halfFOV),
			sinf(atan2f(forwardVector.y, forwardVector.x) + halfFOV)
		};

		Vector2d leftEnd = position.SetVectorOffset(leftBound.ScaleVector(detectionRange));
		Vector2d rightEnd = position.SetVectorOffset(rightBound.ScaleVector(detectionRange));

		DrawLineV({ position.x, position.y }, { leftEnd.x, leftEnd.y }, Fade(YELLOW, 1.f));
		DrawLineV({ position.x, position.y }, { rightEnd.x, rightEnd.y }, Fade(YELLOW, 1.f));

		DrawCircleLines(position.x, position.y, detectionRange, Fade(YELLOW, 1.f));
	}
}
