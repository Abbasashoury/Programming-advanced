#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tortoise
{
private:
    int position;

public:
    void move()
    {
        srand(time(0));
        int RN = rand() % 10 + 1;
        if (RN > 5)
            position += 3;
        else if (RN > 0 && RN < 3)
            position -= 6;
        else if (RN > 2 && RN < 6)
            position += 1;

        if (position < 0)
            position = 0;
        if (position > 99)
            position = 99;
    }
};
class Hare
{
private:
    int position;

public:
    void move()
    {
        srand(time(0));
        int RN = rand() % 10 + 1;
        if (RN < 3)
        {
        }
        else if (RN > 8)
            position += 9;
        else if (RN == 8)
            position -= 12;
        else if (RN > 2 && RN < 6)
            position += 1;
        else if (RN > 5 && RN < 8)
            position -= 2;
        
        if (position < 0)
            position = 0;
        if (position > 99)
            position = 99;
    }
};
class Race
{
private:
    Hare H;
    Tortoise T;

public:
    void CheckWin()
    {
    }
    void ShowRace()
    {
    }
    void Play()
    {
        // "initializ";
        // while (true)
        // {
        //     T.move();
        //     H.move();
        //     CheckWin();
        //     ShowRace();
        //     "duration";
        // }
    }
};

int main()
{

    return 0;
}