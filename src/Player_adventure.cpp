#include "Player_adventure.h"

void Player_adventure::Move()
{
	Mathmatics vectorOffset{ 0.f, 0.f };
	if (IsKeyDown(KEY_W))
	{
		vectorOffset.y -= 1;
	};
	if (IsKeyDown(KEY_S))
	{
		vectorOffset.y += 1;
	};
	if (IsKeyDown(KEY_A))
	{
		vectorOffset.x -= 1;
	};
	if (IsKeyDown(KEY_D))
	{
		vectorOffset.x += 1;
	};
	//if (IsKeyPressed(KEY_LEFT_SHIFT))
	//{
	//	speed = 400.f;
	//};

	vectorOffset = vectorOffset.NormalizeVector();

	position = position.vectorOffset(vectorOffset.vectorScalar(speed * GetFrameTime()));
}

void Player_adventure::Draw(Mathmatics aimDirection)
{
	DrawCircle(position.x, position.y, size, GRAY);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f, position.y + aimDirection.y * 30.f, YELLOW);
}

Mathmatics Player_adventure::aimDirection()
{
	Mathmatics mousePosition{ GetMouseX(), GetMouseY() };
	Mathmatics towardMouseVector = position.vectorTowardTarget(mousePosition).NormalizeVector();

	return towardMouseVector;
}