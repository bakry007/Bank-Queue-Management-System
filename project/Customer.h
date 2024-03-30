#pragma once

#include <string>
using namespace std;
class Customer
{


public:
	string name;
	int EventTime;//arrival or leave Depending on EventType
	string EventType = "Arrival";//arriveor leave
	int WaitingTime;
	int ServiceTime;
	int age;
	
	

	Customer() {}
	Customer(string name, int eventTime, int serviceTime)
	{
		this->name = name;
		this->EventTime = eventTime;


		this->ServiceTime = serviceTime;
		this->age = age;


	}



};