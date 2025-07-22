#include "../Headers/HEADERS.h"
int main() {
     srand(time(0));
    Game game = Game();
    Snake snake = Snake(Width/2, Height/2);
    Food food;

    while (!Stop) {
        clearScreen();
        game.SnakeControl();                 
        game.Flow(snake,food);                      
        game.Display(snake,food.GetPossX(),food.GetPossY());
            Sleep (Density);
    }
    return 1;
}