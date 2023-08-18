#include <iostream>
#include <map>

using namespace std;

map<string, int>::iterator FindByValue(map<string, int>& m, int value)
{
	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		if (i->second == value)
			return i;

	}
	return m.end();
}


struct ID
{
	int id;
	string name;

	ID() {}
	ID(int id, string name) : id(id), name(name){}

	void Show() const
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
	bool operator < (const ID& other) const
	{
		return this->name < other.name;
	}
};

int main() 
{
	map<ID, int> newMap;

	ID first(1, "Taras");

	pair<ID, int> newPair(first, 98);

	newMap.insert(newPair);
	newMap.insert(make_pair(ID(2,"Anna"),88));
	newMap.insert(make_pair(ID(3,"Oksana"),92));
	for (auto i : newMap)
	{
		i.first.Show();
		cout << "Value : " << i.second << endl;
		cout << "_______________________" << endl;
	}
	cout << "**************************************" << endl;

	newMap[ID(7, "Anna")] = 95;
	cout << "Anna : " << newMap[ID(7, "Anna")] << endl;
	for (auto i : newMap)
	{
		i.first.Show();
		cout << "Value : " << i.second << endl;
		cout << "_______________________" << endl;
	}



	/*
	map<string, int> m;

	pair<string, int> newpair("Valia", 9);

	m.insert(newpair);
	m.insert(pair<string, int>("Olga", 4));
	m.insert(make_pair("Petro", 3));

	for (auto i: m)
	{
		cout << "Key : " << i.first << " Value : " << i.second << endl;
	}
	auto res = m.insert(pair<string, int>("Olga", 42));
	pair<map<string,int>::iterator, bool> res2 = m.insert(pair<string, int>("Mukola", 7));

	if (m.insert(pair<string, int>("Olga", 42)).second)
	{
		cout << "Added" << endl;
	}
	else
	{
		cout << "Not added!!!" << endl;
	}

	if (res2.second)
	{
		cout << "Added" << endl;
	}
	else
	{
		cout << "Not added!!!" << endl;
	}
	cout << "---------------------------------------" << endl;
	for (auto i : m)
	{
		cout << "Key : " << i.first << " Value : " << i.second << endl;
	}

	cout << "Value Valia : " << m["Valia"] << endl;
	cout << "Value Olga : " << m["Olga"] << endl;

	map<string,int>::iterator it =  m.find("Olga");
	if (it == m.end())
		cout << "Not found" << endl;
	else
	{
		cout << "Found" << endl;
		cout << "Key : " << it->first << " Value : " << it->second << endl;
		//it->first = "Ira";//error
		it->second = 55;
		cout << "Key : " << it->first << " Value : " << it->second << endl;
	}

	it = FindByValue(m, 55);

	if(it != m.end())
		cout << "Key : " << it->first << " Value : " << it->second << endl;

	cout << "---------------------------------------" << endl;
	for (auto i : m)
	{
		cout << "Key : " << i.first << " Value : " << i.second << endl;
	}
	if (it != m.end())
		m.erase(it);
	cout << "---------------------------------------" << endl;
	for (auto i : m)
	{
		cout << "Key : " << i.first << " Value : " << i.second << endl;
	}

	m["Oleg"] = 100500;
	m["Petro"] = 100500;
	cout << "---------------------------------------" << endl;
	for (auto i : m)
	{
		cout << "Key : " << i.first << " Value : " << i.second << endl;
	}



	*/


}
