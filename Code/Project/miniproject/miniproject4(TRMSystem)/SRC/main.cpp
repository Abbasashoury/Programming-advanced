#include <iostream>
#include "..\include\ResourceManager.h"

using namespace std;

int main()
{
    ResourceManager manager;
    int choice;

    while (true)
    {
        cout << "==============================================\n";
        cout << "1. Add new resource\n";
        cout << "2. Add time interval to resource\n";
        cout << "3. Search resource by name\n";
        cout << "4. Print all schedules\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            cout << "Enter resource id: ";
            cin >> id;
            cout << "Enter resource name: ";
            cin >> name;
            manager.addResource(id, name);
            break;
        }
        case 2:
        {
            int resourceId;
            cout << "Enter resource ID: ";
            cin >> resourceId;

            bool found = false;
            for (int i = 0; i < manager.getResourceCount(); ++i)
            {
                if (manager.getResource(i).getid() == resourceId)
                {
                    int hour, minute;

                    cout << "Enter start time (hour): ";
                    cin >> hour;
                    if (hour < 0 || hour > 23)
                    {
                        cout << "Invalid hour. Please enter hour between 0 and 23.\n";
                        break;
                    }
                    cout << "Enter start time (minute): ";
                    cin >> minute;
                    if (minute < 0 || minute > 59)
                    {
                        cout << "Invalid minute. Please enter minute between 0 and 59.\n";
                        break;
                    }
                    Time start(hour, minute);

                    cout << "Enter end time (hour): ";
                    cin >> hour;
                    if (hour < 0 || hour > 23)
                    {
                        cout << "Invalid hour. Please enter hour between 0 and 23.\n";
                        break;
                    }
                    cout << "Enter end time (minute): ";
                    cin >> minute;
                    if (minute < 0 || minute > 59)
                    {
                        cout << "Invalid minute. Please enter minute between 0 and 59.\n";
                        break;
                    }
                    Time end(hour, minute);

                    manager.getResource(i).addInterval(manager, start, end);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Resource not found.\n";

            break;
        }

        case 3:
        {
            string name;
            cout << "Enter resource name: ";
            cin >> name;
            manager.searchResourceByName(name);
            break;
        }

        case 4:
        {
            manager.printAllSchedules();
            break;
        }

        default:
        {
            cout << "Invalid option. Try again.\n";
        }
        }
    }

    return 0;
}