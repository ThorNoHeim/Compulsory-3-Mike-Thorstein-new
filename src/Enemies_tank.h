#pragma once
#include <raylib.h>
#include <string>
#include "Vector2d.h"

class Enemies_tank
{
public:
    Vector2d position;
    Vector2d forwardVector{ 1, 0 };
    float speed = 150.f;
    float size = 30.f;
    float detectionRange = 300.f;
    float fovAngle = 60.f;
    float rotationSpeed = 0.05f; // Radian/sec
    bool IsAlive{ true };
    bool isDetected{ false };


    void Respawn(int inScreenWidth, int inScreenHeight);

    void update(Vector2d InTargetPosition);

    void Draw();
};
