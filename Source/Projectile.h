#pragma once
#include "raylib.h"
#include "EntityType.h"

struct Projectile
{
public:
    Vector2 lineStart = { 0, 0 };
    Vector2 lineEnd = { 0, 0 };
    int speed = 15;
    Projectile(Vector2 pos, bool isPlayerProjectile) noexcept;
    void Update() noexcept;
    void Render(Texture2D texture) noexcept;
    void Hit() noexcept { active = false; }
    bool isPlayerProjectile() const noexcept { return speed < 0; }
    bool isDead() const noexcept { return !active; }

private:
    static constexpr Vector2 PosOr = { 25, 25 };
    Vector2 position = { 0, 0 };
    bool active = true;
};