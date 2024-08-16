//Develop an employee job scheduling system using a circular linked list. Traverse through all the employee
//tasks one at a time. And find out which employee completes the allotted task first.
//Example:
//Input:
//ID: 001
//Name: AAA
//Number of Tasks: 3
//ID: 002
//Name: AAA
//Number of Tasks: 4
//ID: 003
//Name: AAA
//Number of Tasks: 2
//Output:
//Turn 1: Task of 001
//Turn 2: Task of 002
//Turn 3: Task of 003
//Turn 4: Task of 001
//Turn 5: Task of 002
//Turn 6: Task of 003
//Turn 7: Task of 001
//Turn 8: Task of 002
//Turn 9: Task of 002
//The task completed first is employee 003.
#include <iostream>
#include <string>

using namespace std;

// Define the structure for an Employee
struct Employee {
    string id;
    string name;
    int tasks;
    Employee* next;
};

// Function to add an employee to the circular linked list
Employee* addEmployee(Employee* head, string id, string name, int tasks) {
    Employee* newEmployee = new Employee;
    newEmployee->id = id;
    newEmployee->name = name;
    newEmployee->tasks = tasks;

    if (!head) {
        head = newEmployee;
        newEmployee->next = head;
    } else {
        Employee* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->next = head;
    }
    return head;
}

// Function to traverse the circular linked list and determine task completion
void traverseEmployees(Employee* head) {
    if (!head) return;

    Employee* current = head;
    int turn = 1;
    int totalTasks = 0;
    int minTasks = INT_MAX;
    string firstCompletedEmployee;

    do {
        totalTasks += current->tasks;
        if (current->tasks < minTasks) {
            minTasks = current->tasks;
            firstCompletedEmployee = current->id;
        }
        current = current->next;
    } while (current != head);

    current = head;
    while (totalTasks > 0) {
        if (current->tasks > 0) {
            cout << "Turn " << turn++ << ": Task of " << current->id << endl;
            current->tasks--;
            totalTasks--;
        }
        current = current->next;
    }

    cout << "The task completed first is employee " << firstCompletedEmployee << endl;
}

int main() {
    Employee* head = NULL;
    int task[100],n;
    string id[100], name[100];
    cout<<"-------------MEDIUM :2-----------"<<endl;
    cout<<"Enter number of Employees:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"-------Enter  details for Employee: "<<i+1<<"------"<<endl;
        cout<<"ID:";
        cin>>id[i];
        cout<<"Name:";
        cin>>name[i];
        cout<<"Number of tasks:";
        cin>>task[i];

    }
    cout << "All Employees:" << endl;
    for(int i=0;i<n;i++)
    {
     head = addEmployee(head,id[i],name[i],task[i]);
    }
    traverseEmployees(head);

    return 0;
}
