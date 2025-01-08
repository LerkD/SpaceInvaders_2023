#include "raylib.h"
#include "game.h"
#include "Window.h"


int main(void)
{   
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "SPACE INVADERS");

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
         
    return 0;
}