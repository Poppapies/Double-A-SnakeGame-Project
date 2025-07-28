#include "../Headers/HEADERS.h" //THIS INCLUDE LINE IS BASSED ON THE LOCATION OF THE HEADERS.h FILE

void clearScreen(){
    COORD Possition;
    Possition.X = 0;
    Possition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Possition);
}
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
    if(Stop){
        system("cls");
        std::cout << "\nGAMEOVER\n";
        Score = 0;
    }
        return 1;
    
}
