#include "Player.h"
#include <algorithm>

void Player::UpdateMovement()
{
	int movement = 0;
	if (IsKeyDown(KEY_LEFT))
	{
		movement = -1;
	}
	else if(IsKeyDown(KEY_RIGHT))
	{
		movement = 1;
	}
	x_pos = std::clamp(x_pos += SPEED * movement, PLAYER_RADIUS, static_cast<float>(GetScreenWidth()) - PLAYER_RADIUS);
}
void Player::UpdateAnimation() noexcept
{
	timer += GetFrameTime();
	if (timer > ANIM_SPEED)
	{
		activeTexture = 2 ? activeTexture = 0 : activeTexture++;
		timer = 0;
	}
}
void Player::Update() 
{
	UpdateMovement();
	UpdateAnimation();
}

void Player::Render(Texture2D texture) noexcept
{
	const Rectangle src = { 0,0,static_cast<float>(texture.width), static_cast<float>(texture.height) };
	const Rectangle dst = { x_pos, static_cast<float>(GetScreenHeight()) - PLAYER_BASE_HEIGHT, 100, 100 };
	DrawTexturePro(texture, src, dst, PosOr, 0, WHITE);
}