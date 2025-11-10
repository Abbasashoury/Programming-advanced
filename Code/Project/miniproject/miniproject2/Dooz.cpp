#include <iostream>
#include <string>

using namespace std;

class Player
{

private:
    string player;
    char player_sign;

public:
    Player(string name, char sign) // constructor
    {
        player = name;
        player_sign = sign;
    }
};

class Board
{
private:
    char arr[3][3];
    int counter;

public:
    Board() // ؟؟؟؟؟؟؟؟؟؟
    {
        counter = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                arr[i][j] = ' ';
    }
    void addcounter()
    {
        counter++;
    }
    bool checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if ((arr[i][i] == arr[i][i + 1] && arr[i][i + 1] == arr[i][i + 2]) || (arr[i][i] == arr[i + 1][i] && arr[i + 1][i] == arr[i + 2][i]))
            {
                if (arr[i][i] == 'X')
                {
                }
                else if (arr[i][i] == 'O')
                {
                }
            }
        }
        if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
        {
            if (arr[1][1] == 'X')
            {
            }
            else if (arr[1][1] == 'O')
            {
            }
        }
    }
    bool isFull()
    {
        if (counter > 9)
        {
            cout << "All pLaces is full";
            d.checkequal();
            return false;
        }
        return true;
    }
    void drawBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "-------";
            cout << "|" << arr[i][i] << "|" << arr[i][i + 1] << "|" << arr[i][i + 2] << "|\n";
            cout << "-------";
        }
    }
    void isValidMove(char c);
    void makeMove(char c, int i, int j)
    {
        arr[i][j] = c;
    }
};

class Dooz
{
private:
    int appointment = 1;

public:
    void manageappointment()
    {
        if (appointment == 1)
        {
            b.isValidMove('X');
        }
        else if (appointment == 2)
        {
            b.isValidMove('O');
        }
        appointment = (appointment == 1) ? 2 : 1;
    }
    bool checkequal();
};

void Board::isValidMove(char c)
{
    int i, j;
    cout << "Pleas enter the number of row and column place:\n";
    cin >> i >> j;
    i--;
    j--;
    if (arr[i][j] == 'X' || 'O')
    {
        cout << "place is full";
        drawBoard();
        isValidMove(c);
    }
    makeMove(c, i, j);
}

bool Dooz::checkequal()
{
    cout << "The game is equal";
    return true;
}

int main()
{
    Board b;
    Dooz d;
    Player p1(), p2();
    string name1, name2;
    cout << "Please enter the name of player 1:\n";
    cin >> name1;
    p1() = Player(name1, 'X');
    cout << "Your sign as a player 1 is (X)";
    cout << "Please enter the name of player 2:\n";
    cin >> name2;
    p2() = Player(name2, 'O');
    cout << "Your sign as a player 1 is (O)";

    return 0;
}