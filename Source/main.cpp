#include "raylib.h"
#include "game.h"

int main(void)
{   
    constexpr float SCREEN_WIDTH = 1920.0f;
    constexpr float SCREEN_HEIGHT = 1080.0f;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE INVADERS");

    SetTargetFPS(60);  

    Game game = { State::STARTSCREEN };
    Resources resources;
    game.resources = resources;
    game.Launch();
    
    while (!WindowShouldClose())    
    {
        game.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        game.Render();
        EndDrawing();
    }
    
    CloseWindow();       
    return 0;
}