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
#include <stdlib.h>

class	Mathmatics
{
public:
	float x;
	float y;

	float getPythagoras(); //Pythagoras is used to calculate distances or the magnitude/length of vectors

	float acceleration(float inSpeedIncrease);

	float areaGravity(float gravityQuotient);

	Mathmatics vectorOffset(Mathmatics inVectorToAdd); //is used to change direction

	Mathmatics vectorScalar(float inScalar); //changes movement speed, range and/or power

	Mathmatics NormalizeVector(); //makes it easier to track and change direction

	Mathmatics vectorTowardTarget(Mathmatics inTargetVector); //for targetting

	float targetDistance(Mathmatics inTargetVector); //calculates the distance to target

	float CrossProduct(Mathmatics inOtherVector); //to find the direction of the target. - means target is to the right, + means target is on the left, 0 means the target is right in front of you or right behind you

	float DotProduct(Mathmatics inOtherVector); //deflection/bouncing

	float angleBetweenVectors(Mathmatics inOtherVector); //vision cones/detection/aim assist

	Mathmatics CosineMovement(Mathmatics inCenter, float inAmplitude, float inAngle);

	Mathmatics SineMovement(Mathmatics inCenter, float inAmplitude, float inAngle);

	Mathmatics CircularMotion(Mathmatics inCenter, float inRadius, float inAngle);

	Mathmatics movementCurve(Mathmatics inCenter, float inRadius, float inAngle);
};
