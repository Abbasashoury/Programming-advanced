#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tortoise
{
private:
    int position;

public:
    Tortoise(int base)
    {
        position = base;
    }
    int getpos() const { return position; }
    void move()
    {
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
    Hare(int base)
    {
        position = base;
    }
    int getpos() const { return position; }
    void move()
    {
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
    Race() : H(0), T(0) {}
    bool CheckWin()
    {
        if (H.getpos() == 99 && T.getpos() != 99)
        {
            cout << "Hare is winer\n";
            return true;
        }
        else if (T.getpos() == 99 && H.getpos() != 99)
        {
            cout << "Tortoise is winer\n";
            return true;
        }
        else if (H.getpos() == 99 && T.getpos() == 99)
        {
            cout << "The race is equal\n";
            return true;
        }
        else
            return false;
    }
    void ShowRace()
    {
        for (int i = 0; i < 100; i++)
        {
            if (i == T.getpos() && i == H.getpos())
            {
                cout << "OUCH";
            }
            else if (i == T.getpos())
            {
                cout << "T";
            }
            else if (i == H.getpos())
            {
                cout << "H";
            }
            else
            {
                cout << "-";
            }
        }
        cout << "\n";
    }
    void Play()
    {
        ShowRace();
        while (true)
        {
            bool end = false;
            T.move();
            H.move();
            end = CheckWin();
            ShowRace();
            if (end)
                break;
        }
    }
};

int main()
{
    Race R;
    srand(time(0));
    R.Play();

    return 0;
}