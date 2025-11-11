#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string player;
    char player_sign;

public:
    Player(string name, char sign)
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
    Board()
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
        for (int i = 0; i < 3; ++i)
            if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            {
                if (arr[i][0] == 'X')
                {
                    cout << "Player 1 winer\n";
                    return true;
                }
                else if (arr[i][0] == 'O')
                {
                    cout << "Player 2 winer\n";
                    return true;
                }
            }

        for (int j = 0; j < 3; ++j)
            if (arr[0][j] != ' ' && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
            {
                if (arr[0][j] == 'X')
                {
                    cout << "Player 1 winer\n";
                    return true;
                }
                else if (arr[0][j] == 'O')
                {
                    cout << "Player 2 winer\n";
                    return true;
                }
            }

        if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        {
            if (arr[0][0] == 'X')
            {
                cout << "Player 1 winer\n";
                return true;
            }
            else if (arr[0][0] == 'O')
            {
                cout << "Player 2 winer\n";
                return true;
            }
        }

        if (arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        {
            if (arr[0][2] == 'X')
            {
                cout << "Player 1 winer\n";
                return true;
            }
            else if (arr[0][2] == 'O')
            {
                cout << "Player 2 winer\n";
                return true;
            }
        }
        return false;
    }
    bool isFull()
    {
        if (counter >= 9)
        {
            cout << "All pLaces is full";
            return true;
        }
        return false;
    }
    void drawBoard()
    {
        cout << "\n";
        for (int i = 0; i < 3; i++)
        {
            cout << "-------\n";
            cout << "|" << arr[i][0] << "|" << arr[i][1] << "|" << arr[i][2] << "|\n";
        }
        cout << "-------\n";
    }
    void isValidMove(char c)
    {
        int i, j;
        cout << "Pleas enter the number of row and column place:\n";
        cin >> i >> j;
        if (i > 0 && i < 4 && j > 0 && j < 4)
        {
            i--;
            j--;
            if (arr[i][j] == 'X' || arr[i][j] == 'O')
            {
                cout << "place is full";
                drawBoard();
                isValidMove(c);
            }
            makeMove(c, i, j);
            return;
        }
        cout << "Input invalid";
    }
    void makeMove(char c, int i, int j)
    {
        arr[i][j] = c;
        addcounter();
    }
};

class Dooz
{
private:
    Board *b;
    int appointment = 1;

public:
    Dooz(Board *board)
    {
        b = board;
    }
    void manageappointment()
    {
        if (appointment == 1)
        {
            b->isValidMove('X');
        }
        else if (appointment == 2)
        {
            b->isValidMove('O');
        }
        appointment = (appointment == 1) ? 2 : 1;
    }
    void play()
    {
        cout << "The game is equal";
        return;
    }
};

int main()
{
    Board b;
    Dooz d(&b);
    string name1, name2;
    cout << "Please enter the name of player 1:\n";
    cin >> name1;
    cout << "Your sign as a player 1 is (X)\n";
    cout << "Please enter the name of player 2:\n";
    cin >> name2;
    cout << "Your sign as a player 2 is (O)\n";

    Player p1(name1, 'X');
    Player p2(name2, 'O');

    while (true)
    {
        b.drawBoard();
        d.manageappointment();
        if (b.checkWin())
        {
            b.drawBoard();
            cout << "The Dooz ended\n";
            break;
        }
        if (b.isFull())
        {
            d.play();
            cout << "The Dooz ended. the game have not winer\n";
            break;
        }
    }
    return 0;
}