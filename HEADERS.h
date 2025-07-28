#ifndef HEADERS_H
#define HEADERS_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

enum Direction {UP,DOWN,LEFT,RIGHT};
const int Width = 20;
const int Height = 20;
int Score = 0;
int Density = 100;
bool Stop;
Direction dir;

struct Point{
    int X, Y;
    Point(int XCordinate, int yCordinate) : X(XCordinate), Y(yCordinate) {}
    bool operator==(const Point &other) const{
        return X == other.X && Y == other.Y; 
  }
};

class Food{
private:
int FoodPosstionX; 
int FoodPosstionY;
public:
    int GetPossX();         
    int GetPossY();
    int SetpossX();
    int SetpossY();
};

int Food::SetpossX(){
    FoodPosstionX = 1 + (rand() % (Width - 1));
    return FoodPosstionX;
}
int Food::SetpossY(){
    FoodPosstionY = 1 + (rand() % (Width - 1));
    return FoodPosstionY;
}
int Food::GetPossX(){ return FoodPosstionX;}
int Food::GetPossY(){ return FoodPosstionY;}

class Snake{
private:
    bool growNextMove;
public:
    Snake(int startX, int startY);
    void move();                
    void grow();
    Point getHead() const;
    const std::vector<Point>&getBody() const;
    std::vector<Point>body;
};

Snake::Snake(int startX, int startY){
    body.push_back(Point(startX, startY));
    dir = RIGHT;
    growNextMove = false;
}

void Snake::move(){
    Point head = body.back();

    switch (dir) {
        case UP:    
        head.Y--; 
        break;

        case DOWN:  
        head.Y++; 
        break;

        case LEFT:
        head.X--;
        break;

        case RIGHT:
        head.X++;
        break;
    }

    body.push_back(head);

    if (!growNextMove)
        body.erase(body.begin());  
    else
        growNextMove = false;      
}

void Snake::grow(){
    growNextMove = true;
    Score +=10;
    Density -=5; 
}
Point Snake::getHead() const{return body.back(); }
const std::vector<Point> &Snake::getBody() const{return body; }


class Game{    
public:
void SnakeControl();
void Flow (Snake &s,Food &f);
void Display (const Snake &snake, int Foodx, int FoodY);
};

void Game::SnakeControl(){
    if(_kbhit()){
        switch (_getch()){
                    
            case 'w':
            dir = UP;
            break;
            case 's':
            dir = DOWN;
            break;
            case 'a':
            dir = LEFT;
            break;
            case 'd':
            dir = RIGHT;
            break;
        }
    }
}
void Game::Flow(Snake &s,Food &f){
    s.move();
    Point Head = s.getHead();
    const std::vector<Point>& body = s.getBody();
    
    for (int i =0; i < (body.size() - 1); i++){
        if (Head == body[i])
        Stop = true;
}
    if (Head.X >= Width || Head.X < 0 || Head.Y >= Height ||Head.Y < 0)
    Stop = true;

    if (s.getHead().X == f.GetPossX() && s.getHead().Y == f.GetPossY()) {
        
    while(true) {
        f.SetpossX();
        f.SetpossY();
        bool foodOnBody = false;
        
        for (int i = 0; i < s.body.size(); i++){
                if(body.at(i).X == f.GetPossX() && body.at(i).Y == f.GetPossY()){
                    foodOnBody = true;
                    break;
                }
        }
        
        if (!foodOnBody)
            break;
    }
        s.grow();
        }
}

void Game:: Display (const Snake &snake, int Foodx, int FoodY){
HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < Width; i++){
    SetConsoleTextAttribute(Color,10);
    std::cout << "#";
}
        std::cout << "\n";

    const std::vector<Point> &body = snake.getBody();

    for (int i = 0; i < Height; i++){
        SetConsoleTextAttribute(Color,10);
        std::cout << "#";
        for (int j = 0; j < Width - 2; j++){
            
            Point current(j, i);
            bool isSnake = false;
            for (int k = 0; k < body.size(); k++){
            
                if ( current == body[k]){
                    SetConsoleTextAttribute(Color,4);
                    std::cout << "o";
                    isSnake = true;
                    break;
                }
            }
            if (!isSnake){
                if (i == FoodY && j == Foodx){
                    SetConsoleTextAttribute(Color,6);
                std::cout << "*";}
                else
                std::cout << " ";
            }
        }
        SetConsoleTextAttribute(Color,10);
        std::cout << "#" << "\n";
    }

    for (int i = 0; i < Width; i++){
        SetConsoleTextAttribute(Color,10);
    std::cout << "#";
}
        std::cout << "\n";
            SetConsoleTextAttribute(Color,6);
        std::cout << "Score: " << Score;
}
#endif
