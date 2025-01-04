#pragma once
#include <raylib.h>
#include <vector>

static constexpr int START_AMOUNT = 600;

class Star
{
private:
    Vector2 initPosition = { 0, 0 };
    Vector2 position = { 0, 0 };
    float size = 0;

public: 
    Star(Vector2 pos, float sz) noexcept : initPosition(pos), position(pos), size(sz) {};
    void Update(float offset) noexcept;
    void Render() noexcept;
};

class Background
{
private:
    std::vector<Star> Stars;
    
public:
    Background() noexcept;
    void Update(float offset) noexcept;
    void Render() noexcept;
};