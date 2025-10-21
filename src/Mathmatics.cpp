#include "Mathmatics.h"

float Mathmatics::getPythagoras()
{
	float pythagoras = sqrtf((x * x) + (y * y));

	return pythagoras;
}

//float Mathmatics::acceleration()
//{
//	//acceleration is m/s^2, or meter per second per second, where m/s is speed in meters per second, and acceleration is speed added per second
//
//	return 0.0f;
//}
//
//float Mathmatics::areaGravity(float gravityQuotient)
//{
//	float earthGravity = 9.8; //earth gravity is 9,8 m/s^2
//	float areaGravity = earthGravity * gravityQuotient;
//	return areaGravity;
//}

Mathmatics Mathmatics::vectorOffset(Mathmatics inVectorToAdd)
{
	float newXVector = x + inVectorToAdd.x;
	float newYVector = y + inVectorToAdd.y;
	Mathmatics newVector{ newXVector, newYVector };

	return newVector;
}

Mathmatics Mathmatics::vectorScalar(float inScalar)
{
	float scaledXVector = x * inScalar;
	float scaledYVector = y * inScalar;
	Mathmatics scaledVector{ scaledXVector, scaledYVector };

	return scaledVector;
}

Mathmatics Mathmatics::NormalizeVector()
{
	if (getPythagoras() == 0)
	{
		return { 0, 0 };
	}

	float normalizedXVector = x / getPythagoras();
	float normalizedYVector = y / getPythagoras();
	Mathmatics normalizedVector{ normalizedXVector,normalizedYVector };

	return normalizedVector;
}

Mathmatics Mathmatics::vectorTowardTarget(Mathmatics inTargetVector)
{
	float targetXVector = inTargetVector.x - x;
	float targetyVector = inTargetVector.y - y;
	Mathmatics targettingVector{ inTargetVector.x, inTargetVector.y };

	return targettingVector;
}

float Mathmatics::targetDistance(Mathmatics inTargetVector)
{
	Mathmatics targettingVector = vectorTowardTarget(inTargetVector);
	float targetsDistance = targettingVector.getPythagoras();

	return targetsDistance;
}

float Mathmatics::DotProduct(Mathmatics inOtherVector)
{
	float xComponentMultiplied = x * inOtherVector.x;
	float yComponentMultiplied = y * inOtherVector.y;
	float dotProduct = xComponentMultiplied + yComponentMultiplied;

	return dotProduct;
}

float Mathmatics::angleBetweenVectors(Mathmatics inOtherVector)
{
	float thisLength = getPythagoras();
	float otherLength = inOtherVector.getPythagoras();

	if (thisLength == 0 || otherLength == 0)
	{
		return 0.0f;
	}

	float dotProduct = DotProduct(inOtherVector);
	float cosineDegrees = (acosf(dotProduct / (thisLength * otherLength))) * (180 / 3.14);

	return cosineDegrees;
}

Mathmatics Mathmatics::CosineMovement(Mathmatics inCenter, float inAmplitude, float inAngle)
{
	float x = inCenter.x + inAmplitude * cosf(inAngle);
	float y = inCenter.y;

	return { x, y };
}

Mathmatics Mathmatics::CircularMotion(Mathmatics inCenter, float inRadius, float inAngle)
{
	float cosX = inCenter.x + inRadius * cosf(inAngle);
	float sinY = inCenter.y + inRadius * sinf(inAngle);

	return { cosX, sinY };
}

Mathmatics Mathmatics::movementCurve(Mathmatics inCenter, float inRadius, float inAngle)
{
	return Mathmatics();
}