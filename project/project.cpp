#include <iostream>
#include "Bank.h"
#include <windows.h>
using namespace std;


void SetColor(int ForgC) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ForgC);
}

int main()
{

    Bank b1;
    Customer c1 = Customer("Moe", 35, 62);
    Customer c2 = Customer("Joe", 39, 57);
    Customer c3 = Customer("Kai", 78, 124);
    Customer c4 = Customer("Central", 79, 32);
    Customer c5 = Customer("50Cent", 80, 15);
    Customer c6 = Customer("Kali", 90, 10);
    Customer c7 = Customer("Linux", 95, 20);
    Customer c8 = Customer("Alice", 107, 20);

    b1.addCustomerToPriorityQueue(c1);
    b1.addCustomerToPriorityQueue(c2);
    b1.addCustomerToPriorityQueue(c3);
    b1.addCustomerToPriorityQueue(c4);
    b1.addCustomerToPriorityQueue(c5);
    b1.addCustomerToPriorityQueue(c6);
    b1.addCustomerToPriorityQueue(c7);
    b1.addCustomerToPriorityQueue(c8);

    SetColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    b1.run();

    SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);



    int numOfCusromers;
    cout << "Enter Number of Customers that You Want to Simulate : " ;
    cin >> numOfCusromers;
    for (int i = 0; i < numOfCusromers; i++)
    {
        string name;
        int arrivalTime, serviceTime;
        cout << "Enter Details of Customer " << i + 1 << ":" << endl;
        cout << "Name : ";
        cin >> name;
        cout << "Arrival Time : ";
        cin >> arrivalTime;
        cout << "Service Time : ";
        cin >> serviceTime;

        Customer customer(name, arrivalTime, serviceTime);
        b1.addCustomerToPriorityQueue(customer);


    }
    b1.run();
    



}