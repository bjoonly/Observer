#include "Bidder.h"

UkrainianBuyer::UkrainianBuyer(string name, int money) :name(name), money(money), crypt(nullptr), assets(0) {}

Cryptocurrency* UkrainianBuyer::GetCrypt() const {
	return crypt;
}

void UkrainianBuyer::SetCrypt(Cryptocurrency* crypt) {
	this->crypt = crypt;
}

void UkrainianBuyer::Show() const {
	cout << "Name: " << name << "\nMoney: " << money << endl;
	if (crypt != nullptr)
		cout << assets << " assets of " << crypt->GetName() << endl;
}

void UkrainianBuyer::Update(Cryptocurrency* crypt) {
	if (crypt != this->crypt)
		SetCrypt(crypt);
	vector<int>const& ptr = crypt->GetCourse();
	int random = 0;
	if ((ptr[2] <= ptr[3] && ptr[2] < ptr[4]) && (money / ptr[4]) > 0) {
		random = 1 + rand() % (money / ptr[4]);
		assets += random;
		money -= random * ptr[4];
		cout << endl<<name << " Buy ";
	}
	else if ((ptr[2] >= ptr[3] && ptr[2] > ptr[4]) && assets > 0) {
		random = 1 + rand() % assets;
		assets -= random;
		money += random * ptr[4];
		cout << endl<<name << " Sell ";
	}
	else
		return;
	cout << random << " assets of " << crypt->GetName() << " at sum " << random * ptr[4] << ".\n";

}