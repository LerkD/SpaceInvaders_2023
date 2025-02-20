#include "Player.h"
#include "Utility.h"
#include <algorithm>

void Player::Update()
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
	x_pos = std::clamp(x_pos += SPEED * movement, PLAYER_RADIUS, SCREEN_WIDTH - PLAYER_RADIUS);
}

void Player::Render(Texture2D texture) noexcept
{
	const Rectangle src = { 0,0,static_cast<float>(texture.width), static_cast<float>(texture.height) };
	const Rectangle dst = { x_pos, SCREEN_HEIGHT - PLAYER_BASE_HEIGHT, 100, 100 };
	DrawTexturePro(texture, src, dst, PosOr, 0, WHITE);
}