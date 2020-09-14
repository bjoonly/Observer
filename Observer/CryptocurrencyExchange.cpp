#include "CryptocurrencyExchange.h"

void CryptocurrencyExchange::AddCrypt(Cryptocurrency* crypt) {
	cryptocurrencies.push_back(crypt);
}

void CryptocurrencyExchange::Attach(Bidder* bidder, Cryptocurrency* crypt) {
	crypt->Attach(bidder);
	for (auto elem : bidders) {
		if (elem == bidder)
			return;
	}
	bidders.push_back(bidder);
}

void CryptocurrencyExchange::Detach(Bidder* bidder, Cryptocurrency* crypt) {
	crypt->Detach(bidder);
}

void CryptocurrencyExchange::SetCourses() {
	int random = 0;
	for (auto elem : cryptocurrencies) {
		random = -10 + rand() % 21;
		elem->SetCourse(elem->GetLastCourse() + random);
		elem->ShowCourse();
		cout << endl;
	}
}

void CryptocurrencyExchange::ShowAllBidders() const {
	cout << "*******************************\n";
	for (auto bidder : bidders) {
		bidder->Show();
		cout << "---------------------------------\n";
	}
}