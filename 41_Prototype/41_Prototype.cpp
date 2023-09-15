
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Prototype
{
public :
    virtual T Clone()const = 0;
};

struct Date
{
    int year, month, day;
    string ToString()
    {
        return to_string(year) + " / " + to_string(month) + " / " + to_string(day);
    }
};

class Member : public Prototype<Member>
{
private :
    string name;
    int age;
public:
    Member():name("no name"), age(0){}
    Member(string name, int age):name( name), age(age){}
    string ToString()
    {
        return name + " " + to_string(age);
    }
    Member Clone()const override
    {
        return *this;
    }
   
};

class Event : public Prototype<Event>
{
private:
    string name;//Independency day
    Date date;//2024/8/24
    string address;//Kyiv
    Member* members;//0x2154546
    int countMember;//2
public:
    Event(): name("no name"), date(Date{0,0,0}),address("no address"), 
        members(nullptr), countMember(0){}
    Event(string name, Date date, string address): name(name), date(date),address(address), 
        members(nullptr), countMember(0){}
    Event(const Event & other)
    {
        this->name = other.name;//Independency day
        this->date = other.date;//2024/8/24
        this->address = other.address;//Kyiv
       // this->members = other.members;//0x2154546
        this->members = new Member[other.countMember];
        for (int i = 0; i < other.countMember; i++)
        {
            this->members[i] = other.members[i];
        }
        this->countMember = other.countMember;//2
    }

    Event Clone()const override
    {
        Event clone = *this;
        //Independency day
       //2024/8/24
        //Kyiv
        //0x2154546
        clone.members = new Member[this->countMember];
        for (int i = 0; i < this->countMember; i++)
        {
            clone.members[i] = this->members[i].Clone();
        }
        //2
        return clone;
    }
    void AddTestMembers()
    {
        countMember = 2;
        members = new Member[countMember];
        members[0] = Member("Bob", 22);
        members[1] = Member("Tom", 35);
    }

    string ToString()
    {
        string res = name + " : " + date.ToString() + " \n" + address + "\n";
        for (int i = 0; i < countMember; i++)
        {
            res += "\tMember [" + to_string(i + 1) + "] " + members[i].ToString() + "\n";
        }
        return res;
    }
    ~Event()
    {
        delete[]members;
    }
};


int main()
{
    Event event("Independency day", Date {2024, 8, 24}, "Kyiv, Ukraine");
    event.AddTestMembers();
    cout << "Event : " << event.ToString() << endl;

    Event copy(event);//copy constructor
    cout << "Copy : " << copy.ToString() << endl;

    Event clone = event.Clone();
    cout << "Clone : " << clone.ToString() << endl;

  
}

