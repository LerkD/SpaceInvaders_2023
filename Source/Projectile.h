#pragma once
#include "raylib.h"
#include "EntityType.h"

struct Projectile
{
public:
    Vector2 lineStart = { 0, 0 };
    Vector2 lineEnd = { 0, 0 };
    Projectile(Vector2 pos, bool isPlayerProjectile) noexcept;
    void Update() noexcept;
    void Render(Texture2D texture) noexcept;
    void Hit() noexcept { active = false; }
    [[nodiscard]] bool isPlayerProjectile() const noexcept { return speed < 0; }
    [[nodiscard]] bool isDead() const noexcept { return !active; }

private:
    int speed = 15;
    static constexpr Vector2 PosOr = { 25, 25 };
    Vector2 position = { 0, 0 };
    bool active = true;
};