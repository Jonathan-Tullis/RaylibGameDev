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


    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins
        DrawCircle(circle_x, circle_y, 25, BLUE);

        /*
         Move Right and bound it to 350 since the right most coordinate is 350,0
         Since we have a variable called width which may change, we use it instead of just 350
        */
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x = circle_x + 10;
        }

        /*
         Move left and bound it to 0 since the left coordinate is 0,0
        */
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x = circle_x - 10;
        }


        // Game logic ends
        EndDrawing();
    }
}