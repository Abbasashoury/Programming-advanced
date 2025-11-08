#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct student
{
    string name;
    string password;
    int wallet;
    bool primarycharge = false;
    vector<string> BorrowedBooks;
};
vector<student> Student;
vector<string> Books;

int IDstudent = 0;

void AddBook();
void EditBook();
void AddStu();
void ShowStu();
void ShowWallet();
void ShowBooks();
void BackBorrow();
void Borrow();
void ChargeWallet();

string toLower(string str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
void loadData()
{
    ifstream studentfile("students.txt");
    if (studentfile)
    {
        while (true)
        {
            student stu;
            if (!(studentfile >> stu.name >> stu.password >> stu.wallet >> stu.primarycharge))
                break;

            stu.BorrowedBooks.clear();

            string book;
            while (studentfile.peek() != '\n' && studentfile >> book)
            {
                stu.BorrowedBooks.push_back(book);
            }

            Student.push_back(stu);
        }
    }

    ifstream bookfile("Books.txt");
    if (bookfile)
    {
        string book;
        while (getline(bookfile, book))
        {
            if (!book.empty())
            {
                Books.push_back(book);
            }
        }
    }
}
void saveData()
{
    ofstream studentfile("students.txt");
    if (studentfile)
    {
        for (int i = 0; i < Student.size(); i++)
        {
            studentfile << Student.at(i).name << " "
                        << Student.at(i).password << " "
                        << Student.at(i).wallet << " "
                        << Student.at(i).primarycharge;

            for (int j = 0; j < Student.at(i).BorrowedBooks.size(); j++)
            {
                studentfile << " " << Student.at(i).BorrowedBooks.at(j);
            }
            studentfile << endl;
        }
    }

    ofstream bookfile("Books.txt");
    if (bookfile)
    {
        for (int i = 0; i < Books.size(); i++)
        {
            bookfile << Books.at(i) << endl;
        }
    }
}

int main()
{
    loadData();

    int login;
    while (true)
    {
        cout << "login as:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Student" << endl;
        cout << "0. Exit" << endl;
        cin >> login;
        switch (login)
        {
        case 1:
        {
            string password;
            cout << "enter the password:";
            cin >> password;

            if (password == "admin123")
            {
                bool ExitWhlie = false;
                while (true)
                {
                    cout << " welcome admin choose one of the commands" << endl;
                    cout << " add book = 1" << endl;
                    cout << " edit book = 2" << endl;
                    cout << " add student = 3" << endl;
                    cout << " show student = 4" << endl;
                    cout << " show wallet = 5" << endl;
                    cout << " exit = 0" << endl;
                    int command;
                    cin >> command;
                    {
                        switch (command)
                        {
                        case 1:
                        {
                            AddBook();
                            break;
                        }
                        case 2:
                        {
                            EditBook();
                            break;
                        }
                        case 3:
                        {
                            AddStu();
                            break;
                        }
                        case 4:
                        {
                            ShowStu();
                            break;
                        }
                        case 5:
                        {
                            ShowWallet();
                            break;
                        }
                        case 0:
                        {
                            ExitWhlie = true;
                            break;
                        }
                        default:
                        {
                            cout << "command not valide";
                        }
                        }
                        if (ExitWhlie)
                            break;
                    }
                }
            }
            else
            {
                cout << "password not valid";
            }
            break;
        }
        case 2:
        {

            bool identify = false;
            string name, password;
            cout << "enter the name :" << endl;
            cin.ignore();
            getline(cin, name);
            name = toLower(name);

            cout << "enter the password:" << endl;
            cin >> password;
            for (int i = 0; i < Student.size(); i++)
            {
                if (Student.at(i).name == name && Student.at(i).password == password)
                {
                    IDstudent = i;
                    identify = true;
                }
            }

            if (identify)
            {
                bool ExitWhlie = false;
                while (true)
                {
                    cout << " welcome student choose one of the commands" << endl;
                    cout << " show books = 1" << endl;
                    cout << " borrow = 2" << endl;
                    cout << " pay back a borrow = 3" << endl;
                    cout << " charge your wallet = 4" << endl;
                    cout << " exit = 0" << endl;
                    int command;
                    cin >> command;
                    {
                        switch (command)
                        {
                        case 1:
                        {
                            ShowBooks();
                            break;
                        }
                        case 2:
                        {
                            Borrow();
                            break;
                        }
                        case 3:
                        {
                            BackBorrow();
                            break;
                        }
                        case 4:
                        {
                            ChargeWallet();
                            break;
                        }
                        case 0:
                        {
                            ExitWhlie = true;
                            break;
                        }
                        default:
                        {
                            cout << "command not valide";
                        }
                        }
                        if (ExitWhlie)
                            break;
                    }
                }
            }
            else
            {
                cout << "password not valid or student not found";
            }
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "command not valide";
            break;
        }
        }
    }
    return 0;
}

void AddBook()
{
    string book;
    cout << "please inter the name of the book or exit(-1)" << endl;
    cin.ignore();
    getline(cin, book);
    book = toLower(book);

    if (book == "-1")
        return;

    Books.push_back(book);
    cout << book << " add to books" << endl;

    saveData();
}
void EditBook()
{
    int flag = 0;
    string book;
    cout << "please inter the name of the book you want to change or exit(-1)" << endl;
    cin.ignore();
    getline(cin, book);
    book = toLower(book);

    if (book == "-1")
        return;

    int i = 0;
    while (i < Books.size())
    {
        if (Books.at(i) == book)
        {
            string newbook;
            cout << "please inter a new name of the (" << book << ") :" << endl;
            getline(cin, newbook);
            newbook = toLower(newbook);

            Books.at(i) = newbook;
            flag = 1;
            cout << "change of the book name was successful" << endl;

            saveData();
            break;
        }
        i++;
    }
    if (!flag)
    {
        cout << "book not found or name of the book in question not valid" << endl;
        EditBook();
    }
}
void AddStu()
{
    string name, password;
    int wallet;
    cout << "pleas enter the name and password of student or exit(-1)" << endl;
    cin.ignore();
    getline(cin, name);
    name = toLower(name);

    if (name == "-1")
        return;

    for (int i = 0; i < Student.size(); i++)
    {
        if (Student.at(i).name == name)
        {
            cout << "a student with this name already exist. please choose amother name" << endl;
            AddStu();
        }
    }

    cin >> password;

    Student.push_back({name, password, 50, {}});
    cout << name << " add to Student" << endl;

    saveData();
}
void ShowStu()
{

    for (int i = 0; i < Student.size(); i++)
    {
        cout << endl
             << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl
             << "||" << left << setw(50) << Student.at(i).name << "||" << left << setw(50) << Student.at(i).password << "||" << endl
             << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    }
    cout << endl;
}
void ShowWallet()
{
    int flag = 0;
    string name;
    cout << "please enter the name of the student who wants to see wallet or exit(-1)" << endl;
    cin.ignore();
    getline(cin, name);
    name = toLower(name);

    if (name == "-1")
        return;

    int i = 0;
    while (i < Student.size())
    {
        if (Student.at(i).name == name)
        {

            cout << " wallet of (" << name << ") = " << Student.at(i).wallet << endl;
            flag = 1;
            break;
        }
        i++;
    }
    if (!flag)
    {
        cout << " the student not found or name of the student in question not valid" << endl;
        ShowWallet();
    }
}
void ShowBooks()
{

    for (int i = 0; i < Books.size(); i++)
    {
        cout << endl
             << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "||" << left << setw(70) << Books.at(i) << "||" << endl
             << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    }
    cout << endl;

    cout << endl;
    int ask = 0;
    cout << " Do you want to borrow a book: Yes(1) or No(0)" << endl;
    cin >> ask;
    if (ask)
    {
        Borrow();
    }
}
void Borrow()
{
    string bookname;
    int flag_bookfound = 0;
    if (!(Student.at(IDstudent).primarycharge))
    {
        cout << "you must charge your wallet at least once" << endl;
        ChargeWallet();
    }
    cout << "please enter the name of book you was borrowing or exit(-1):" << endl;
    cin.ignore();
    getline(cin, bookname);
    bookname = toLower(bookname);

    if (bookname == "-1")
        return;
    for (int i = 0; i < Books.size(); i++)
    {
        if (Books.at(i) == bookname)
        {
            flag_bookfound = 1;
            if (Student.at(IDstudent).wallet > 2)
            {
                Student.at(IDstudent).wallet -= 2;
                Student.at(IDstudent).BorrowedBooks.push_back(bookname);
                Books.erase(Books.begin() + i);
                cout << "book (" << bookname << ") was borrowed" << endl;

                saveData();
                return;
            }
            cout << "your money is not enough.";
            break;
        }
    }
    if (!flag_bookfound)
    {
        cout << "book not found or name of the book in question not valid";
    }
}
void BackBorrow()
{
    string bookname;
    cout << "please enter the name of book you want to pay back borrow or exit(-1):" << endl;
    cin.ignore();
    getline(cin, bookname);
    bookname = toLower(bookname);

    if (bookname == "-1")
        return;
    for (int i = 0; i < Student.at(IDstudent).BorrowedBooks.size(); i++)
    {
        if (Student.at(IDstudent).BorrowedBooks.at(i) == bookname)
        {
            Books.push_back(Student.at(IDstudent).BorrowedBooks.at(i));
            Student.at(IDstudent).BorrowedBooks.erase(Student.at(IDstudent).BorrowedBooks.begin() + i);
            cout << "book (" << bookname << ") was pay back borrowed" << endl;

            saveData();
            return;
        }
    }
    cout << "book not found or name of the book in question not valid" << endl;
}
void ChargeWallet()
{
    int amountofmoney;
    cout << "please enter amount of money you want to add to your wallet or exit(-1):" << endl;
    cin >> amountofmoney;
    if (amountofmoney == -1)
        return;
    Student.at(IDstudent).wallet += amountofmoney;
    Student.at(IDstudent).primarycharge = true;
    cout << " charge your wallet succesfully" << endl;

    saveData();
}