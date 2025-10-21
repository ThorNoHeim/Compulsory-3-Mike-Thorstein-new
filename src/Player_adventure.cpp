//#include "Player_adventure.h"
//
//void Player_adventure::Move()
//{
//	Vector2d setVectorOffset{ 0.f, 0.f };
//	if (IsKeyDown(KEY_W))
//	{
//		setVectorOffset.y -= 1;
//	};
//	if (IsKeyDown(KEY_S))
//	{
//		setVectorOffset.y += 1;
//	};
//	if (IsKeyDown(KEY_A))
//	{
//		setVectorOffset.x -= 1;
//	};
//	if (IsKeyDown(KEY_D))
//	{
//		setVectorOffset.x += 1;
//	};
//	//if (IsKeyPressed(KEY_LEFT_SHIFT))
//	//{
//	//	speed = 400.f;
//	//};
//
//	setVectorOffset = setVectorOffset.NormalizeVector();
//
//	position = position.SetVectorOffset(setVectorOffset.ScaleVector(speed * GetFrameTime()));
//}
//
//void Player::Draw(Vector2d aimDirection)
//{
//	DrawCircle(position.x, position.y, size, GRAY);
//	DrawLine(position.x, position.y, position.x + aimDirection.x * 30.f, position.y + aimDirection.y * 30.f, YELLOW);
//}
//
//Vector2d Player::aimDirection()
//{
//	Vector2d mousePosition{ GetMouseX(), GetMouseY() };
//	Vector2d towardMouseVector = position.VectorTowardsTarget(mousePosition).NormalizeVector();
//
//	return towardMouseVector;
//}