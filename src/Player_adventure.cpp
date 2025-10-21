#include "Player_adventure.h"

void Player_adventure::Move()
{
	Mathmatics setVectorOffset{ 0.f, 0.f };
	if (IsKeyDown(KEY_W))
	{
		setVectorOffset.y -= 1;
	};
	if (IsKeyDown(KEY_S))
	{
		setVectorOffset.y += 1;
	};
	if (IsKeyDown(KEY_A))
	{
		setVectorOffset.x -= 1;
	};
	if (IsKeyDown(KEY_D))
	{
		setVectorOffset.x += 1;
	};
	//if (IsKeyPressed(KEY_LEFT_SHIFT))
	//{
	//	speed = 400.f;
	//};

	setVectorOffset = setVectorOffset.NormalizeVector();

	position = position.vectorOffset(setVectorOffset.vectorScalar(speed * GetFrameTime()));
}

void Player::Draw(Mathmatics aimDirection)
{
	DrawCircle(position.x, position.y, size, GRAY);
	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f, position.y + aimDirection.y * 30.f, YELLOW);
}

Mathmatics Player::aimDirection()
{
	Mathmatics mousePosition{ GetMouseX(), GetMouseY() };
	Mathmatics towardMouseVector = position.VectorTowardsTarget(mousePosition).NormalizeVector();

	return towardMouseVector;
}