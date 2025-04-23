#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Raylib i VS Code!");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hej från Raylib!", 200, 200, 20, DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
