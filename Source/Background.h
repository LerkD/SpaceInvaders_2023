#pragma once
#include <raylib.h>
#include <vector>

static constexpr int START_AMOUNT = 600;

class Star
{
private:
    Vector2 position = { 0, 0 };
    inline static float offset;
    float size = 0;

public: 
    Star(Vector2 pos, float sz) noexcept : position(pos), size(sz) {};
    void Update(float _offset) noexcept { offset = _offset; }
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