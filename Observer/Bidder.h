#pragma once
#include"Cryptocurrency.h"

class Bidder {
public:
	virtual void Update(class Cryptocurrency*) = 0;
	virtual void Show()const=0;
};

class UkrainianBuyer : public Bidder {
	class Cryptocurrency* crypt;
	string name;
	int money;
	int assets;
public:
	UkrainianBuyer(string name, int money = 100000);
	class Cryptocurrency* GetCrypt()const;

	void SetCrypt(class Cryptocurrency* crypt);
	void Show()const override;
	void Update(class Cryptocurrency* crypt);

};


