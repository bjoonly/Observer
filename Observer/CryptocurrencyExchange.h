#pragma once
#include"Bidder.h"
#include"Cryptocurrency.h"
class CryptocurrencyExchange {
	list<Cryptocurrency*>cryptocurrencies;
	list<Bidder*>bidders;
public:
	void AddCrypt(Cryptocurrency* crypt);
	void Attach(Bidder* bidder, Cryptocurrency* crypt);
	void Detach(Bidder* bidder, Cryptocurrency* crypt);
	void SetCourses();
	void ShowAllBidders()const;
};