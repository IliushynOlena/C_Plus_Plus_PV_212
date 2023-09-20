#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
enum Status{None, Increase, Decrease};

struct CryptoCurrency
{
	string name;
	double price;
	Status status;
	int incCount = 0;
	int decCount = 0;

	CryptoCurrency(string n, double p)
	{
		name = n;
		price = p;
		status = None;
		incCount = 0;
		decCount = 0;
	}
	void SetNewPrice(double newPrice)
	{
		if (newPrice > price)
		{
			incCount++;
			decCount = 0;
			if (incCount >= 3) status = Increase;
			else status = None;
		}
		else if (newPrice < price)
		{
			decCount++;
			incCount = 0;
			if (decCount >= 3)status = Decrease;
			else status = None;
		}
		price = newPrice;
	}

};

class Trader
{
	string name;
	double balance;
public:
	void Update(CryptoCurrency* currency)
	{
		switch (currency->status)
		{
		case None:cout << "I am : " << name<< "Do nothing! " << currency->name << endl;break;
		case Increase:cout << "I am : " << name << "Sell " << currency->name << endl;break;
		case Decrease:cout << "I am : " << name << "Buy " << currency->name << endl;break;
		}
	}
};

class Exchange
{
private:
	vector<CryptoCurrency*> cryptos;
	vector<Trader*> traders;
public:
	Exchange()
	{
		cryptos.push_back(new CryptoCurrency("Bitcoin", 27000));
		cryptos.push_back(new CryptoCurrency("Dollar", 38.8));
		cryptos.push_back(new CryptoCurrency("Euro", 42.5));
	}
	void Subscribe(Trader* trader)
	{
		traders.push_back(trader);
	}
	double RandomPrice(double price)
	{
		return price + rand() % 21 -10;//-10...10
	}
	void GenerateCourse()
	{
		for (auto c : cryptos)
		{
			c->SetNewPrice(RandomPrice(c->price));
			//notify all subscribers
			Notify(c);
		}
	}
	void Notify(CryptoCurrency * currency)
	{
		for (auto t : traders)
		{
			t->Update(currency);
		}
	}
	void StartTraders()
	{
		for (int i = 0; i < 1000; i++)
		{
			GenerateCourse(); 
			Sleep(1000);
			cout << endl << endl;
		}
	}
};

int main()
{
	Exchange exchange;

	Trader* td1 = new Trader();
	Trader* td2 = new Trader();
	Trader* td3 = new Trader();

	exchange.Subscribe(td1);
	exchange.Subscribe(td2);
	exchange.Subscribe(td3);

	exchange.StartTraders();

	delete td1;
	delete td2;
	delete td3;
   
}

