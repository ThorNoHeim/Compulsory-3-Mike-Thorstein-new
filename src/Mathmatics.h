#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <random>
#include <raylib.h>
#include <string>
#include <vector>
#include <ostream>
#include <corecrt_math.h>

class	Mathmatics
{
public:
	float x;
	float y;

	float getPythagoras(); //Pythagoras is used to calculate distances or the magnitude/length of vectors

	//float acceleration();

	//float areaGravity(float gravityQuotient);

	Mathmatics vectorOffset(Mathmatics inVectorToAdd); //is used to change direction

	Mathmatics vectorScalar(float inScalar); //changes movement speed, range and/or power

	Mathmatics NormalizeVector(); //makes it easier to track and change direction

	Mathmatics vectorTowardTarget(Mathmatics inTargetVector);

	float targetDistance(Mathmatics inTargetVector);

	float CrossProduct(Mathmatics inOtherVector);

	float DotProduct(Mathmatics inOtherVector);

	float angleBetweenVectors(Mathmatics inOtherVector);

	Mathmatics CosineMovement(Mathmatics inCenter, float inAmplitude, float inAngle);

	Mathmatics CircularMotion(Mathmatics inCenter, float inRadius, float inAngle);

	Mathmatics movementCurve(Mathmatics inCenter, float inRadius, float inAngle);
};
