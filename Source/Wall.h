#pragma once
#include "raylib.h"

static constexpr int WALL_RADIUS = 60;
static constexpr int FONT_SIZE = 40;
static constexpr Vector2 PosOrig = { 100, 100 };

class Wall
{
private:
    Vector2 position;
    int health = 50;
    Rectangle PosDest = { position.x, position.y, 200, 200 };
    int PosX = static_cast<int>(position.x - 21);
    int PosY = static_cast<int>(position.y + 10);

public:
    Wall(float posX, float posY) noexcept : position{ posX, posY } {};
    void Render(Texture2D texture) noexcept;
    void DecreaseHealth() noexcept { health -= 1; };
    [[nodiscard]] Vector2 GetPosition() const noexcept { return position; };
    [[nodiscard]] bool IsDead() const noexcept { return health < 1; };
}; 
