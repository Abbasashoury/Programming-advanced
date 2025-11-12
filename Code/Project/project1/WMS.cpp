#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstring>
#include <stack>

using namespace std;

struct User
{
    char username[50];
    char password[50];
    double wallet;
    bool isAdmin;
};

struct UserAdmin
{
    char username[50];
    char password[50];
    bool isAdmin;
};

struct Product
{
    char name[50];
    double price;
    int quantity;
};

struct ProductChange
{
    char name[50];
    double price;
    int quantity;
};

const int MAX_ADMINS = 2;
const int MAX_USERS = 3;
const int MAX_PRODUCTS = 100;

UserAdmin admins[MAX_ADMINS];
User users[MAX_USERS];
Product products[MAX_PRODUCTS];
int adminCount = 0;
int userCount = 0;
int productCount = 0;
char loggedInUser[50];
bool isAdminMode = false;

stack<ProductChange> undoStack;

void toLower(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0 && c != '.')
            return false;
    }
    return true;
}

void loadData()
{
    ifstream adminFile("admins.txt");
    if (adminFile)
    {
        while (adminFile >> admins[adminCount].username >> admins[adminCount].password >> admins[adminCount].isAdmin)
        {
            adminCount++;
            if (adminCount >= MAX_ADMINS)
                break;
        }
    }

    ifstream userFile("users.txt");
    if (userFile)
    {
        while (userFile >> users[userCount].username >> users[userCount].password >> users[userCount].wallet >> users[userCount].isAdmin)
        {
            userCount++;
            if (userCount >= MAX_USERS)
                break;
        }
    }

    ifstream productFile("products.txt");
    if (productFile)
    {
        while (productFile >> products[productCount].name >> products[productCount].price >> products[productCount].quantity)
        {
            productCount++;
            if (productCount >= MAX_PRODUCTS)
                break;
        }
    }
    else
    {
        ofstream newFile("products.txt");
        if (newFile.is_open())
        {
            newFile << "apple 2.5 400\n"
                    << "banana 1.5 100\n"
                    << "cherry 3.0 150\n"
                    << "orange 4.5 100\n"
                    << "melon 1.5 200\n"
                    << "coconut 3.5 50\n"
                    << "pineapple 2.0 40\n"
                    << "fig 1.5 200\n"
                    << "carrot 3.0 350\n"
                    << "pear 1.0 250\n";
            newFile.close();
            loadData();
        }
        else
        {
            cout << "Error creating products file!\n";
        }
    }
}
void saveData()
{
    ofstream adminFile("admins.txt");
    for (int i = 0; i < adminCount; i++)
    {
        adminFile << admins[i].username << " "
                  << admins[i].password << " "
                  << admins[i].isAdmin << endl;
    }

    ofstream userFile("users.txt");
    for (int i = 0; i < userCount; i++)
    {
        userFile << users[i].username << " "
                 << users[i].password << " "
                 << users[i].wallet << " "
                 << users[i].isAdmin << endl;
    }

    ofstream productFile("products.txt");
    for (int i = 0; i < productCount; i++)
    {
        productFile << products[i].name << " "
                    << products[i].price << " "
                    << products[i].quantity << endl;
    }
}

int findUserIndex(const char *username)
{
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
            return i;
    }
    return -1;
}

int findAdminIndex(const char *username)
{
    for (int i = 0; i < adminCount; i++)
    {
        if (strcmp(admins[i].username, username) == 0)
            return i;
    }
    return -1;
}

int findProductIndex(const char *name)
{
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].name, name) == 0)
            return i;
    }
    return -1;
}

void showHelp(const char *command = nullptr)
{
    if (!command || strcmp(command, "command") == 0)
    {
        cout << "Available commands:\n";
        cout << "1. show <product name> or 'show item'\n"
             << "2. buy <product name> <quantity>\n"
             << "3. balance\n"
             << "4. help command\n"
             << "5. help <command>\n";
    }
    else
    {
        string cmd(command);
        if (cmd == "show")
            cout << "Usage: show <product name> - Display product info\n";
        else if (cmd == "buy")
            cout << "Usage: buy <product name> <quantity> - Purchase items\n";
        else if (cmd == "balance")
            cout << "Usage: balance - Show wallet balance\n";
        else if (cmd == "help")
            cout << "Usage: help command - List all commands\n";
        else
            cout << "Unknown command!\n";
    }
}

void showProducts(const char *item = nullptr)
{
    if (item == nullptr)
    {
        for (int i = 0; i < productCount; i++)
        {
            cout << products[i].name << " - Price: "
                 << products[i].price << " - Quantity: "
                 << products[i].quantity << endl;
        }
    }
    else
    {
        int idx = findProductIndex(item);
        if (idx == -1)
        {
            cout << "Product not found!\n";
        }
        else
        {
            cout << products[idx].name << " - Price: "
                 << products[idx].price << " - Quantity: "
                 << products[idx].quantity << endl;
        }
    }
}

void buyProduct(const char *item, int quantity, int currentUserIndex)
{
    int productIdx = findProductIndex(item);
    if (productIdx == -1)
    {
        cout << "Product not found!\n";
        return;
    }
    if (products[productIdx].quantity < quantity)
    {
        cout << "Insufficient stock!\n";
        return;
    }
    double total = products[productIdx].price * quantity;
    if (users[currentUserIndex].wallet < total)
    {
        cout << "Insufficient balance!\n";
        return;
    }
    users[currentUserIndex].wallet -= total;
    products[productIdx].quantity -= quantity;
    cout << "Purchase successful! Remaining balance: " << users[currentUserIndex].wallet << endl;
    saveData();
}

void showBalance(int currentUserIndex)
{
    cout << "Your balance: " << users[currentUserIndex].wallet << endl;
}

void addProduct(const char *item, double price)
{
    int idx = findProductIndex(item);
    if (idx != -1)
    {
        products[idx].quantity++;
        products[idx].price = price;
        cout << "Product quantity increased! New quantity: " << products[idx].quantity << endl;
    }
    else
    {
        if (productCount >= MAX_PRODUCTS)
        {
            cout << "Product capacity full!\n";
            return;
        }
        strcpy(products[productCount].name, item);
        products[productCount].price = price;
        products[productCount].quantity = 1;
        productCount++;
        cout << "Product added!\n";
    }
    saveData();
}

void removeProduct(const char *item)
{
    int idx = findProductIndex(item);
    if (idx == -1)
    {
        cout << "Product not found!\n";
        return;
    }

    ProductChange change;
    strcpy(change.name, products[idx].name);
    change.price = products[idx].price;
    change.quantity = products[idx].quantity;
    undoStack.push(change);

    if (products[idx].quantity > 1)
    {
        products[idx].quantity--;
        cout << "One item removed! Remaining quantity: " << products[idx].quantity << endl;
    }
    else
    {
        for (int i = idx; i < productCount - 1; i++)
        {
            products[i] = products[i + 1];
        }
        productCount--;
        cout << "Product completely removed!\n";
    }

    saveData();
}

void undoLastRemove()
{
    if (undoStack.empty())
    {
        cout << "No removed products to undo!\n";
        return;
    }

    ProductChange lastChange = undoStack.top();
    undoStack.pop();

    int idx = findProductIndex(lastChange.name);
    if (idx == -1)
    {
        if (productCount >= MAX_PRODUCTS)
        {
            cout << "Product capacity full! Cannot undo.\n";
            return;
        }
        strcpy(products[productCount].name, lastChange.name);
        products[productCount].price = lastChange.price;
        products[productCount].quantity = lastChange.quantity;
        productCount++;
        cout << "Product '" << lastChange.name << "' restored!\n";
    }
    else
    {
        products[idx].quantity++;
        cout << "Quantity of product '" << lastChange.name << "' increased to pervious quantity " << "!\n";
    }

    saveData();
}

void renameProduct(const char *item, const char *newName)
{
    int idx = findProductIndex(item);
    if (idx == -1)
    {
        cout << "Product not found!\n";
        return;
    }
    strcpy(products[idx].name, newName);
    cout << "Product name updated!\n";
    saveData();
}

void updatePrice(const char *item, double newPrice)
{
    int idx = findProductIndex(item);
    if (idx == -1)
    {
        cout << "Product not found!\n";
        return;
    }
    products[idx].price = newPrice;
    cout << "Price updated!\n";
    saveData();
}

void addCredit(const char *username, double amount)
{
    int idx = findUserIndex(username);
    if (idx == -1)
    {
        cout << "User not found!\n";
        return;
    }
    users[idx].wallet += amount;
    cout << "Credit added! New balance: " << users[idx].wallet << endl;
    saveData();
}

int main()
{
    loadData();

    while (true)
    {
        char choice;
        cout << "Do you want to (L)ogin or (S)ign up? (or type '-1' to quit): ";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 's')
        {
            while (true)
            {
                char username[50], password[50];
                cout << "Username (or type 'exit' to go back): ";
                cin >> username;
                if (strcmp(username, "exit") == 0)
                    break;

                cout << "Password: ";
                cin >> password;

                char userType;
                cout << "(A)dmin or (U)ser? (or type 'exit' to go back): ";
                cin >> userType;
                userType = tolower(userType);

                if (userType == 'a')
                {
                    if (adminCount >= MAX_ADMINS)
                    {
                        cout << "Admin capacity full! Please try again.\n";
                        continue;
                    }
                    if (findAdminIndex(username) != -1)
                    {
                        cout << "Username already exists! Please try again.\n";
                        continue;
                    }
                    strcpy(admins[adminCount].username, username);
                    strcpy(admins[adminCount].password, password);
                    admins[adminCount].isAdmin = true;
                    adminCount++;
                    cout << "Admin registration successful!\n";
                    saveData();
                    break;
                }

                else if (userType == 'u')
                {
                    if (userCount >= MAX_USERS)
                    {
                        cout << "User capacity full! Please try again.\n";
                        continue;
                    }
                    if (findUserIndex(username) != -1)
                    {
                        cout << "Username already exists! Please try again.\n";
                        continue;
                    }
                    strcpy(users[userCount].username, username);
                    strcpy(users[userCount].password, password);
                    users[userCount].wallet = 10000;
                    users[userCount].isAdmin = false;
                    userCount++;
                    cout << "User registration successful!\n";
                    saveData();
                    break;
                }
                else if (strcmp(&userType, "exit") == 0)
                {
                    break;
                }
                else
                {
                    cout << "Invalid user type! Please try again.\n";
                    continue;
                }
            }
        }

        else if (choice == 'l')
        {
            while (true)
            {
                char username[50], password[50];
                cout << "Username (or type 'exit' to go back): ";
                cin >> username;
                if (strcmp(username, "exit") == 0)
                    break;

                cout << "Password: ";
                cin >> password;

                int currentUserIndex = findUserIndex(username);
                int currentAdminIndex = findAdminIndex(username);

                if (currentUserIndex == -1 && currentAdminIndex == -1)
                {
                    cout << "Login failed! Please try again.\n";
                    continue;
                }

                if (currentUserIndex != -1)
                {
                    if (strcmp(users[currentUserIndex].password, password) != 0)
                    {
                        cout << "Login failed! Please try again.\n";
                        continue;
                    }
                }
                else if (currentAdminIndex != -1)
                {
                    if (strcmp(admins[currentAdminIndex].password, password) != 0)
                    {
                        cout << "Login failed! Please try again.\n";
                        continue;
                    }
                }

                isAdminMode = (currentAdminIndex != -1);
                strcpy(loggedInUser, username);
                cout << "Welcome " << loggedInUser << "!\n";

                while (true)
                {
                    cout << (isAdminMode ? "$ " : "# ");
                    char input[100];

                    cin.getline(input, 100);
                    char *command = strtok(input, " ");

                    if (command == nullptr)
                    {
                        cout << "Invalid command! Use help for guidance\n";
                        continue;
                    }
                    toLower(command);

                    if (strcmp(command, "exit") == 0)
                    {
                        break;
                    }

                    if (!isAdminMode)
                    {
                        if (strcmp(command, "show") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            if (item != nullptr)
                            {
                                toLower(item);
                                if (strcmp(item, "item") == 0)
                                {
                                    showProducts();
                                }
                                else
                                {
                                    showProducts(item);
                                }
                            }
                            else
                            {
                                cout << "Invalid command! Use 'show <product name>' or 'show item'.\n";
                            }
                        }
                        else if (strcmp(command, "buy") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            char *quantityStr = strtok(nullptr, " ");
                            if (item != nullptr && quantityStr != nullptr)
                            {
                                toLower(item);
                                if (!isNumber(quantityStr))
                                {
                                    cout << "Quantity must be a positive number!\n";
                                    continue;
                                }
                                int quantity = atoi(quantityStr);
                                buyProduct(item, quantity, currentUserIndex);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: buy <product name> <quantity>\n";
                            }
                        }
                        else if (strcmp(command, "balance") == 0)
                        {
                            showBalance(currentUserIndex);
                        }
                        else if (strcmp(command, "help") == 0)
                        {
                            char *cmd = strtok(nullptr, " ");
                            if (cmd != nullptr)
                            {
                                toLower(cmd);
                                if (strcmp(cmd, "command") == 0)
                                {
                                    showHelp();
                                }
                                else
                                {
                                    showHelp(cmd);
                                }
                            }
                            else
                            {
                                cout << "Invalid command! Use 'help command' to see all commands or 'help <command>' for details.\n";
                            }
                        }
                        else
                        {
                            cout << "Invalid command! Use help for guidance\n";
                        }
                    }
                    else
                    {
                        if (strcmp(command, "add") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            char *priceStr = strtok(nullptr, " ");
                            if (item != nullptr && priceStr != nullptr)
                            {
                                toLower(item);
                                if (!isNumber(priceStr))
                                {
                                    cout << "Price must be a positive number!\n";
                                    continue;
                                }
                                double price = atof(priceStr);
                                addProduct(item, price);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: add <product name> <price>\n";
                            }
                        }
                        else if (strcmp(command, "remove") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            if (item != nullptr)
                            {
                                toLower(item);
                                removeProduct(item);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: remove <product name>\n";
                            }
                        }
                        else if (strcmp(command, "rename") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            char *newName = strtok(nullptr, " ");
                            if (item != nullptr && newName != nullptr)
                            {
                                toLower(item);
                                toLower(newName);
                                renameProduct(item, newName);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: rename <product name> <new name>\n";
                            }
                        }
                        else if (strcmp(command, "price") == 0)
                        {
                            char *item = strtok(nullptr, " ");
                            char *newPriceStr = strtok(nullptr, " ");
                            if (item != nullptr && newPriceStr != nullptr)
                            {
                                toLower(item);
                                if (!isNumber(newPriceStr))
                                {
                                    cout << "Price must be a positive number!\n";
                                    continue;
                                }
                                double newPrice = atof(newPriceStr);
                                updatePrice(item, newPrice);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: price <product name> <new price>\n";
                            }
                        }
                        else if (strcmp(command, "credit") == 0)
                        {
                            char *username = strtok(nullptr, " ");
                            char *amountStr = strtok(nullptr, " ");
                            if (username != nullptr && amountStr != nullptr)
                            {
                                toLower(username);
                                if (!isNumber(amountStr))
                                {
                                    cout << "Amount must be a positive number!\n";
                                    continue;
                                }
                                double amount = atof(amountStr);
                                addCredit(username, amount);
                            }
                            else
                            {
                                cout << "Invalid command format! Use: credit <username> <amount>\n";
                            }
                        }
                        else if (strcmp(command, "undo") == 0)
                        {
                            undoLastRemove();
                        }
                        else
                        {
                            cout << "Invalid command! Use help for guidance\n";
                        }
                    }
                }
                break;
            }
        }
        else if (choice == '-1')
        {
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    saveData();
    return 0;
}