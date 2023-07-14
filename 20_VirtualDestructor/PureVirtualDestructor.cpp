#include <iostream>
using namespace std;

class Person//absract
{
    string name;
public:
    Person() :name(""){}
    Person(string name) :name(name) {}
   
    virtual void Print()const
    {
        cout << "\nName : " << name << endl;
        cout << "\n_______________________" << endl;
    }
    virtual ~Person() = 0 {}
   
};
class Aspirant : public Person
{
    string* subjects;
    int countSubject;
public:
    Aspirant(string name, initializer_list<string> list) :
        Person(name)
    {
        this->countSubject = list.size();
        subjects = new string[countSubject];
        int i = 0;
        for (string s : list)
        {
            subjects[i] = s;
            i++;
        }
    }
    void Print()const
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSubject; i++)
        {
            cout << subjects[i] << " ";
        }
    }
    ~Aspirant()
    {
        if (subjects != nullptr)
            delete[]subjects;
    }
};

int main()
{
    srand(time(0));
    /* Student student("Petro","Programmer");
     student.Print();

     Aspirant aspirant("Petro Oldest", "Water Engineer", { "Recuperation","Math","Pump"});
     aspirant.Print();*/

    Person* groups[2]{
        //new Person("Petro"),//constructor
        new Aspirant("Petro Oldest", { "Recuperation","Math","Pump"}),//constructor
        new Aspirant("Olya",  { "UI/UX","Pattern","Main page"}),//constructor
    };
    for (int i = 0; i < 2; i++)
    {
        groups[i]->Print();
        delete groups[i];//Destructor
    }

}//Destructor

