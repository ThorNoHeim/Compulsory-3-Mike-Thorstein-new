#include "Player_adventure.h"

void Player_adventure::Move()
{
	Mathmatics newVector{ 0.f, 0.f };
	if (IsKeyDown(KEY_W))
	{
		newVector.y -= 1;
	};
	if (IsKeyDown(KEY_S))
	{
		newVector.y += 1;
	};
	if (IsKeyDown(KEY_A))
	{
		newVector.x -= 1;
	};
	if (IsKeyDown(KEY_D))
	{
		newVector.x += 1;
	};
	//if (IsKeyPressed(KEY_LEFT_SHIFT))
	//{
	//	speed = 400.f;
	//};

	newVector = newVector.NormalizeVector();

	position = position.vectorOffset(newVector.vectorScalar(playerSpeed * GetFrameTime()));
}

void Player_adventure::Draw(Mathmatics aimDirection)
{
	DrawCircle(position.x, position.y, playerSize, GRAY);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f, position.y + aimDirection.y * 30.f, YELLOW);
}

Mathmatics Player_adventure::aimDirection()
{
	Mathmatics mousePosition{ GetMouseX(), GetMouseY() };
	Mathmatics towardMouseVector = position.vectorTowardTarget(mousePosition).NormalizeVector();

	return towardMouseVector;
}