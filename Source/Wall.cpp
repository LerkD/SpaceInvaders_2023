#include "Wall.h"

void Wall::Render(Texture2D texture) noexcept
{
	DrawTexturePro(texture, { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) }, PosDest, PosOrig, 0, WHITE);
	DrawText(TextFormat("%i", health), PosX, PosY, FONT_SIZE, RED);
}
