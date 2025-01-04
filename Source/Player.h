#pragma once
#include "raylib.h"
#include "EntityType.h"

static constexpr float PLAYER_BASE_HEIGHT = 70.0f;
static constexpr float PLAYER_RADIUS = 50.0f;
constexpr float SPEED = 7.0f;
constexpr float ANIM_SPEED = 0.4f;
static constexpr Vector2 PosOr = { 50,50 };

class Player
{
private:
    float x_pos = static_cast<float>(GetScreenWidth()) / 2.0f;
    int lives = 3;
    float timer = 0;
    int activeTexture = 0;

    void UpdateMovement();
    void UpdateAnimation() noexcept;

public:
    EntityType type = EntityType::PLAYER;

    void Render(Texture2D texture) noexcept;
    void Update();
    bool IsDead() const noexcept { return lives <= 0; };
    float GetPosition() const noexcept { return x_pos; };
    int GetLives() const noexcept { return lives; };
    int GetActiveTexture() const noexcept { return activeTexture; };
    void DecreaseHealth() noexcept { lives--; };
};