#include "raylib.h"

int main()
{
    // Window Dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Jonathan's Window");

    // Circle Dimentions
    int circle_x{300};
    int circle_y{100};
    int circle_radius{25};


    // Circle Edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};



    // Axe Dimensions
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};

    // Axe Edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};



    int direction{10};


    bool collision_with_axe = 
    
            (b_axe_y >= u_circle_y) && 
            (u_axe_y <= b_circle_y) && 
            (l_axe_x <= r_circle_x) && 
            (r_axe_x >= l_circle_x);




    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe == true)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else 
        {
            // Game logic begins

            // Update the edges of the circle and axe since they are moving
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            
            // Update the collision with the axe
            collision_with_axe = 
                (b_axe_y >= u_circle_y) && 
                (u_axe_y <= b_circle_y) && 
                (l_axe_x <= r_circle_x) && 
                (r_axe_x >= l_circle_x);


            // Draw the circle and axe
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            /*
             Move Right and bound it to 350 since the right most coordinate is 350,0
             Since we have a variable called width which may change, we use it instead of just 350
            */
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            /*
             Move left and bound it to 0 since the left coordinate is 0,0
            */
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

        }
        
        // Game logic ends
        EndDrawing();

    }
}