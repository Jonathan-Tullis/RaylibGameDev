#include "raylib.h"

int main()
{
    // Window Dimensions
    int width{350};
    int height{200};
    InitWindow(width, height, "Jonathan's Window");

    // Circle Dimentions
    int circle_x{width/2};
    int circle_y{height/2};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins
        DrawCircle(circle_x, circle_y, 25, BLUE);

        // Game logic ends
        EndDrawing();
    }
}