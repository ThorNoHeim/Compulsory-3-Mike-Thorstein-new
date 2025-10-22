#include "Attacks_tank.h"
void Attacks_tank::Shoot(Vector2d inStart, Vector2d inDirection, float speed) {
    position = inStart;
    velocity = inDirection.ScaleVector(speed);
    IsAlive = true;

}

void Attacks_tank::Update() {
    if (IsAlive) {
        position = position.SetVectorOffset(velocity.ScaleVector(GetFrameTime()));
        if (position.x < 0, position.x > GetScreenWidth(), position.y < 0, position.y > GetScreenHeight()) {
            IsAlive = false;
        }
    }
}

void Attacks_tank::Draw() {
    if (IsAlive) {
        DrawRectangle(position.x, position.y, 5.f, 5.f, GREEN);
    }
}
