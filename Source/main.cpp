#include "raylib.h"
#include "game.h"
#include "Utility.h"


int main(void)
{   
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE INVADERS");

    SetTargetFPS(60);  

    Game game = Game();
    
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