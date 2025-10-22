#pragma once
#include <raylib.h>
#include <string>
#include "Vector2d.h"

class Attacks_tank {
public:
    Vector2d position;
    Vector2d velocity;
    bool IsAlive{ false };

    void Shoot(Vector2d inStart, Vector2d inDirection, float speed);

    void Update();

    void Draw();

};
