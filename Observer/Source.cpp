#include "CryptocurrencyExchange.h"
#include<ctime>



int main() {	
	srand(unsigned(time(0)));
	CryptocurrencyExchange cryptExc;
	Bitcoin* bitcoin=new Bitcoin;
	Ethereum* ethereum = new Ethereum;
	XRP* xrp = new XRP;
	Litecoin* litecoin = new Litecoin;
	Tether* tether = new Tether;
	cryptExc.AddCrypt(bitcoin);
	cryptExc.AddCrypt(ethereum);
	cryptExc.AddCrypt(xrp);
	cryptExc.AddCrypt(litecoin);
	cryptExc.AddCrypt(tether);
	UkrainianBuyer* ukB1 = new UkrainianBuyer("Petro");
	UkrainianBuyer* ukB2 = new UkrainianBuyer("Bogdan",1000000);
	UkrainianBuyer* ukB3 = new UkrainianBuyer("Katya");
	UkrainianBuyer* ukB4 = new UkrainianBuyer("Nastya", 2000000);
	UkrainianBuyer* ukB5 = new UkrainianBuyer("Vlad");

	
	cryptExc.Attach(ukB2, bitcoin);
	cryptExc.Attach(ukB1, ethereum);
	cryptExc.Attach(ukB3, xrp);
	cryptExc.Attach(ukB4, litecoin);
	cryptExc.Attach(ukB5, tether);
	for (int i = 0; i < 10; i++) {
		cryptExc.SetCourses();	
		cryptExc.ShowAllBidders();
		Sleep(1000);
	}
	delete bitcoin;
	delete ethereum;
	delete xrp;
	delete litecoin;
	delete tether;
	delete ukB1;
	delete ukB2;
	delete ukB3;
	delete ukB4;
	delete ukB5;
	return 0;
}