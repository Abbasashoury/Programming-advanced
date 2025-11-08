#include <iostream>

using namespace std;
struct Student
{
    string name;
    int studentID;
    int units;
    float gpa;
    string securityCode;
    Student *next;
};

void addStudent(Student *&head);
bool deletestudent(Student *&head);
Student *searchStudent(Student *head);
bool updateStudent(Student *head);
void displayAllRecords(Student *head);

int main()
{
    Student *student = nullptr;

    cout << "Hello Alleykom" << endl;

    while (true)
    {
        int n = 0;
        bool exit = false;
        cout << "choose of the function :" << endl;
        cout << "add student:         (1)" << endl;
        cout << "delete student:      (2)" << endl;
        cout << "search student:      (3)" << endl;
        cout << "update student:      (4)" << endl;
        cout << "display all records: (5)" << endl;
        cout << "exit:               (-1)" << endl;

        cin >> n;

        switch (n)
        {
        case 1:
        {
            addStudent(student);
            break;
        }

        case 2:
        {
            if (deletestudent(student))
            {
                cout << "--------------------------------" << endl;
                cout << "delete student succesfully" << endl;
                cout << "--------------------------------" << endl;
            }
            else
            {
                cout << "--------------------------------" << endl;
                cout << "delete student Unsuccesfully" << endl;
                cout << "--------------------------------" << endl;
            }

            break;
        }

        case 3:
        {
            Student *stu = searchStudent(student);

            if (stu != nullptr)
            {
                cout << "--------------------------------" << endl;
                cout << "student found" << endl;
                cout << "name: " << stu->name << endl;
                cout << "id: " << stu->studentID << endl;
                cout << "units: " << stu->units << endl;
                cout << "gpa: " << stu->gpa << endl;
                cout << "security code: " << stu->securityCode << endl;
                cout << "--------------------------------" << endl;
            }
            else
            {
                cout << "--------------------------------" << endl;
                cout << "student not found!" << endl;
                cout << "--------------------------------" << endl;
            }
            break;
        }

        case 4:
        {
            if (updateStudent(student))
            {
                cout << "--------------------------------" << endl;
                cout << "update student succesfully" << endl;
                cout << "--------------------------------" << endl;
            }
            else
            {
                cout << "--------------------------------" << endl;
                cout << "update student Unsuccesfully" << endl;
                cout << "--------------------------------" << endl;
            }

            break;
        }

        case 5:
        {
            displayAllRecords(student);
            break;
        }
        case -1:
        {
            exit = true;
            break;
        }

        default:
            break;
        }
        if (exit)
            break;
    }

    return 0;
}

void addStudent(Student *&head)
{
    Student *newstu = new Student;
    cout << "--------------------------------" << endl;
    cout << " enter the name:" << endl;
    cin >> newstu->name;
    cout << " enter the student id:" << endl;
    cin >> newstu->studentID;
    cout << " enter the units:" << endl;
    cin >> newstu->units;
    cout << " enter the gpa:" << endl;
    cin >> newstu->gpa;
    cout << " enter the security code:" << endl;
    cin >> newstu->securityCode;
    newstu->next = nullptr;

    if (head == nullptr)
    {
        head = newstu;
        cout << "--------------------------------" << endl;
        cout << "add student succesfully" << endl;
        cout << "--------------------------------" << endl;

        return;
    }
    Student *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newstu;
    cout << "--------------------------------" << endl;
    cout << "add student succesfully" << endl;
    cout << "--------------------------------" << endl;
}
bool deletestudent(Student *&head)
{
    int studentid = 0;
    cout << "--------------------------------" << endl;
    cout << " enter the student id:" << endl;
    cin >> studentid;

    if (head == nullptr)
        return false;

    if (head->studentID == studentid)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Student *temp = head;
    while (temp->studentID != studentid && temp->next != nullptr)
    {
        temp = temp->next;
    }
    if (temp->studentID == studentid)
    {
        Student *temp2 = head;
        while (temp2->next != temp && temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }

        if (temp2->next == temp)
        {
            temp2->next = temp->next;
            delete temp;
        }

        return true;
    }
    else
    {
        return false;
    }
}
Student *searchStudent(Student *head)
{
    int studentid = 0;
    cout << "--------------------------------" << endl;
    cout << " enter the student id:" << endl;
    cin >> studentid;

    Student *temp = head;
    while (temp != nullptr && temp->studentID != studentid)
    {
        temp = temp->next;
    }
    if (temp != nullptr && temp->studentID == studentid)
    {
        return temp;
    }
    else
    {
        return nullptr;
    }
}
bool updateStudent(Student *head)
{
    int studentid = 0;

    if (head == nullptr)
        return false;

    cout << "--------------------------------" << endl;
    cout << " enter the student id:" << endl;
    cin >> studentid;

    Student *temp = head;
    while (temp != nullptr && temp->studentID != studentid)
    {
        temp = temp->next;
    }
    if (temp != nullptr && temp->studentID == studentid)
    {
        cout << "--------------------------------" << endl;
        cout << " enter the student new gpa:" << endl;
        cin >> temp->gpa;
        cout << " enter the student new units:" << endl;
        cin >> temp->units;

        return true;
    }
    return false;
}
void displayAllRecords(Student *head)
{
    if (head == nullptr)
    {
        cout << "--------------------------------" << endl;
        cout << " list of files is empty" << endl;
        return;
    }
    Student *temp = head;
    int i = 0;
    while (temp != nullptr)
    {
        cout << "----------------------------------------" << endl;
        cout << "name of student [" << i << "] : " << temp->name << endl;
        cout << "student id of student [" << i << "] : " << temp->studentID << endl;
        cout << "units of student [" << i << "] : " << temp->units << endl;
        cout << "gpa of student [" << i << "] : " << temp->gpa << endl;
        cout << "security code of student [" << i << "] : " << temp->securityCode << endl;
        cout << "----------------------------------------" << endl;

        temp = temp->next;
        i++;
    }
}