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
    int PosX = position.x - 21;
    int PosY = position.y + 10;

public:
    Wall(float posX, float posY) noexcept : position{ posX, posY } {};
    void Render(Texture2D texture) noexcept;
    void DecreaseHealth() noexcept { health -= 1; };
    Vector2 GetPosition() const noexcept { return position; };
    bool IsDead() const noexcept { return health < 1; };
}; 
