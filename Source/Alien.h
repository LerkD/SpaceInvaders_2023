#pragma once
#include "raylib.h"


static constexpr float ALIEN_RADIUS = 30.0f;
static constexpr Vector2 DT_o = { 50, 50 };

class Alien
{
public:
private:
    int speed = 2; 
    Vector2 position = { 0, 0 };
    bool active = true;

public: 
    explicit Alien(float x, float y) noexcept;
    void Update() noexcept;
    void Render(Texture2D texture) noexcept;
    void Kill() noexcept { active = false; }
   [[nodiscard]] bool isDead() const noexcept { return !active; }
   [[nodiscard]] bool HasReachedYPosition(int boundary) const noexcept { return position.y > boundary; }
   [[nodiscard]] Vector2 GetPosition() const noexcept { return position; }

};