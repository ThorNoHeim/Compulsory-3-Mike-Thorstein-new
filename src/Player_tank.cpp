#include "Player_tank.h"

void Player_tank::Move() {
    Vector2d offsetPosition{ 0.f, 0.f };
    if (IsKeyDown(KEY_W)) {
        offsetPosition.y -= 1;
    }
    else if (IsKeyDown(KEY_S)) {
        offsetPosition.y += 1;
    }
    else if (IsKeyDown(KEY_D)) {
        offsetPosition.x += 1;
    }
    else if (IsKeyDown(KEY_A)) {
        offsetPosition.x -= 1;
    }

    offsetPosition = offsetPosition.NormalizeVector();

    position = position.SetVectorOffset(offsetPosition.ScaleVector(speed * GetFrameTime()));
}

void Player_tank::Draw(Vector2d aimDirection) {
    DrawRectangle(position.x, position.y, size, size, VIOLET);
    DrawCircle(position.x, position.y, 10.f, PINK);
    DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f, position.y + aimDirection.y * 30.f, RED);
}

Vector2d Player::AimDirection() {
    Vector2d mousePosition{ GetMouseX(), GetMouseY() };
    Vector2d towardsMouseVector = position.VectorTowardsTarget(mousePosition).NormalizeVector();

    return towardsMouseVector;
}

