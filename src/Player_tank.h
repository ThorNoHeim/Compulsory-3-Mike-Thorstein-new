#pragma once
#include <raylib.h>
#include <string>
#include "Vector2d.h"

class Player {
public:
    Vector2d position;
    float speed = 200.f;
    float size = 25.f;

    void Move();
    void Draw(Vector2d aimDirection);

    Vector2d AimDirection();
};
