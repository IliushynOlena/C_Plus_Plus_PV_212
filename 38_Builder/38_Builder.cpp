#include <iostream>
using namespace std;

class Laptop
{
private:
	string screenResolution;
	string proccessor;
	string memory;
	string hdd;
	string battery;
public:
	void SetResolution(string value) { screenResolution = value; }
	void SetProccessor(string value) { proccessor = value; }
	void SetMemory(string value) { memory = value; }
	void SetHDD(string value) { hdd = value; }
	void SetBattery(string value) { battery = value; }
	void Show()const
	{
		cout << "Screen Resolution : " << screenResolution << endl;
		cout << "Proccessor : " << proccessor << endl;
		cout << "Memory : " << memory << endl;
		cout << "HDD : " << hdd << endl;
		cout << "Battery : " << battery << endl;
	}
};
class LaptopBuilder
{
protected:
	Laptop* laptop;
public:
	void CreateLaptop()
	{
		laptop = new Laptop();
	}
	Laptop* GetLaptop()
	{
		return laptop;
	}

	virtual void SetMonitorResolution() = 0;
	virtual void SetProccessor() = 0;
	virtual void SetMemory() = 0;
	virtual void SetHDD() = 0;
	virtual void SetBattery() = 0;
};
class GamingLaptopBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution()override
	{
		laptop->SetResolution("1900x1200");
	}
	void SetProccessor()override
	{
		laptop->SetProccessor("Intel Core I7, 2.9GHZ");
	}
	void SetMemory()override
	{
		laptop->SetMemory("32 GB");
	}
	void SetHDD()override
	{
		laptop->SetHDD("1 Tb");
	}
	void SetBattery()override {
		laptop->SetBattery("5000 mAh");
	}
};
class ProgrammerLaptopBuilder : public LaptopBuilder
{
public:
	void SetMonitorResolution()override
	{
		laptop->SetResolution("2000x1200");
	}
	void SetProccessor()override
	{
		laptop->SetProccessor("Intel Core I9, 2.9GHZ");
	}
	void SetMemory()override
	{
		laptop->SetMemory("64 GB");
	}
	void SetHDD()override
	{
		laptop->SetHDD("1 Tb");
	}
	void SetBattery()override {
		laptop->SetBattery("7000 mAh");
	}
};
class LaptopDirector
{
	LaptopBuilder* builder;
public:
	LaptopDirector(LaptopBuilder* builder = nullptr) : builder(builder) {}
	
	~LaptopDirector()
	{
		delete builder;
	}
	void SetBuilder(LaptopBuilder* builder)
	{
		if (this->builder != nullptr)delete this->builder;
		this->builder = builder;
	}
	Laptop* GetLeptop()
	{
		return builder->GetLaptop();
	}
	void Configuration()
	{
		builder->CreateLaptop();
		builder->SetMonitorResolution();
		builder->SetProccessor();
		builder->SetMemory();
		builder->SetHDD();
		builder->SetBattery();
	}
};

int main()
{
	LaptopDirector dir;
	dir.SetBuilder(new GamingLaptopBuilder());
	dir.Configuration();

	Laptop * laptop = dir.GetLeptop();
	laptop->Show();

	dir.SetBuilder(new ProgrammerLaptopBuilder());
	dir.Configuration();
	cout << endl;
	delete laptop;
	laptop = dir.GetLeptop();
	laptop->Show();

	delete laptop;
	
}

