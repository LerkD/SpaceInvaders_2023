#include "Background.h"

Background::Background() noexcept
{
	for (int i = 0; i < START_AMOUNT; i++)
	{
		const Vector2 tmpPos{ static_cast<float>(GetRandomValue(-150, GetScreenWidth() + 150)), static_cast<float>(GetRandomValue(0, GetScreenHeight())) };
		const float tmpSize = static_cast<float>(GetRandomValue(1.0f, 4.0f) / 2.0f);
		Stars.push_back(Star(tmpPos, tmpSize));
	}
}
void Background::Update(float offset) noexcept
{
	for (auto& star : Stars)
	{
		Stars.at(0).Update(offset);
	}
}
void Background::Render() noexcept
{
	for (auto& star : Stars)
	{
		star.Render();
	}
}

void Star::Render() noexcept 
{
	DrawCircle(static_cast<int>(position.x + offset), static_cast<int>(position.y), size, SKYBLUE);
}