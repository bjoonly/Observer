#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<list>
#include<Windows.h>
using namespace std;

class Bidder;


class Cryptocurrency{
protected:
	string name;
	vector<int>course;
	list<class Bidder*>bidders;
public:
	Cryptocurrency(string name, int course);

	void Attach(Bidder* bidder);

	void Detach(Bidder* bidder);
	void Notify();
	string GetName()const;
	const vector<int>& GetCourse()const;
	int GetLastCourse()const;
	void SetCourse(int course);
	void ShowCourse()const;
	

};

class  Bitcoin :public Cryptocurrency {
public:
	Bitcoin(int course = 300000) :Cryptocurrency("Bitcoin", course) {}
};

class  Ethereum :public Cryptocurrency {
public:
	Ethereum(int course = 10560) :Cryptocurrency("Ethereum", course) {}
};

class  XRP :public Cryptocurrency {
public:
	XRP(int course = 7) :Cryptocurrency("XRP", course) {}
};

class  Litecoin :public Cryptocurrency {
public:
	Litecoin(int course = 1371) :Cryptocurrency("Litecoin", course) {}
};

class Tether :public Cryptocurrency {
public:
	Tether(int course = 28) :Cryptocurrency("Tether", course) {}
};

