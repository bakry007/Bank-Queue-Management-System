#pragma once
#include <string>
#include "Customer.h"
#include <iostream>
#include <queue>
using namespace std;
struct compareEventTime
{
	bool operator()(const Customer& lhs, Customer& rhs) const
	{
		return  lhs.EventTime > rhs.EventTime;

	}
};

class Bank
{
private:
	priority_queue<Customer, vector<Customer>, compareEventTime> customerPriorityQueue;
	int teller_num = 3;
	int totalServeTime;
	int totalWaitingTime;

	queue<Customer> bankQueue;
	int currentTime = 0;
	

public:
	void addCustomerToPriorityQueue(Customer c)
	{
		customerPriorityQueue.push(c);
	}

	void addCustomerToBankQueue(Customer c2)
	{
		bankQueue.push(c2);
	}

	void run()
	{
		while (!customerPriorityQueue.empty())
		{

			Customer cuurentCustomer = customerPriorityQueue.top();
			currentTime = cuurentCustomer.EventTime;
			customerPriorityQueue.pop();

			if (cuurentCustomer.EventType == "Arrival")
			{
				if (teller_num != 0)
				{
					cuurentCustomer.WaitingTime = currentTime - cuurentCustomer.EventTime;
					cuurentCustomer.EventTime = currentTime + cuurentCustomer.ServiceTime;
					totalWaitingTime += cuurentCustomer.WaitingTime;
					totalServeTime += cuurentCustomer.ServiceTime;
					
					
					cuurentCustomer.EventType = "Leave";
					cout << "customer name : " << cuurentCustomer.name << " Waiting Time : " << cuurentCustomer.WaitingTime << " Service Time : " << cuurentCustomer.ServiceTime << " Leave Time : " << cuurentCustomer.EventTime << endl;
					teller_num--;
					addCustomerToPriorityQueue(cuurentCustomer);
				}
				else
				{
					addCustomerToBankQueue(cuurentCustomer);
				}
			}
			else if (cuurentCustomer.EventType == "Leave")
			{


				if (!bankQueue.empty())
				{

					Customer current = bankQueue.front();
					current.WaitingTime = currentTime - current.EventTime;
					current.EventTime = currentTime + current.ServiceTime;
					totalWaitingTime += cuurentCustomer.WaitingTime;
					totalServeTime += cuurentCustomer.ServiceTime;
					current.EventType = "Leave";
					cout << "customer name : " << current.name << " Waiting Time : " << current.WaitingTime << " Service Time : " << current.ServiceTime << " Leave Time : " << current.EventTime << endl;
					addCustomerToPriorityQueue(current);
					bankQueue.pop();
				}
				else
				{
					teller_num++;
				}
				
				

			}
		}
		cout <<"the total waiting time is : "<< totalWaitingTime << endl;

		cout <<"the total serve time is : "<< totalServeTime << endl;
	}
};	