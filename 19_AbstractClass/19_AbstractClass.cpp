#include <iostream>
using namespace std;

class Animal // abstract class
{
protected:
    float weight;
    int speed;
    string type;
    string name;
    string place;
public:
    Animal() :weight(0), speed(0), type(""), name(""), place("") {}
    Animal(float w, int s, string t, string n, string p) : 
        type(t), name(n), place(p) 
    {
        //1
       /* if (w < 0)
            this->weight = 0;
        else
            this->weight = w;*/
        //2
        //(w > 0) ? this->weight = w : this->weight = 0;
        //3
        this->weight = w > 0 ? w : 0;
        this->speed = s > 0 ? s : 0;    
    }
    void Print()const
    {
        cout << "Weight : " << weight << " kg " << endl;
        cout << "Speed : " << speed << " km/g " << endl;
        cout << "Type : " << type <<  endl;
        cout << "Name : " << name <<  endl;
        cout << "Place : " << place <<  endl;
    }
    virtual void Move()const
    {
        cout << "I am moving......" << endl;
    }
    virtual void MakeSound()const = 0;// pure virtual method
};

class Lion : public Animal
{
    int soundStrength;
public:
    Lion() :soundStrength(0), Animal() {}
    Lion(float w, int s, string t, string n, string p, int sound) :soundStrength(sound), 
        Animal(w,s,t,n,p) {}
    void MakeSound()const override
    {
        cout << "Rrrrrrrrrrrr-rrrrrrrrrrr-rrrrrrrrrr" << endl;
        cout << "I have sound Strength " << soundStrength << "Db"<< endl;
    }
    void Move()const
    {
        cout << "I am running with speed "<< speed << "km/g" << endl;
    }    
};
class Duck : public Animal
{
    float flyHeight;
public:
    Duck() :flyHeight(0), Animal() {}
    Duck(float w, int s, string t, string n, string p, float h) :flyHeight(h),
        Animal(w,s,t,n,p) {}
    
    void MakeSound()const override
    {
        cout << "Kra-kra-kra-kra-kra-kra-kra" << endl;
    }
    void Move()const
    {
        cout << "I am swimming and flying up to  " << flyHeight << "km" << endl;
    }
};

class Reptile : public Animal//abstract class
{
    float swimDeep;
public:
    Reptile() :swimDeep(0), Animal() {}
    Reptile(float w, int s, string t, string n, string p, float deep) :
        swimDeep(deep), Animal(w,s,t,n,p) {}
    void Move()const
    {
        cout << "I am crowling and  swimming up to  " << swimDeep << "km" << endl;
    }
};

class Frog : public Reptile
{
    float jumpLenght;
public:
    Frog() :jumpLenght(0), Reptile() {}
    Frog(float w, int s, string t, string n, string p, float deep, float j) :jumpLenght(j), 
        Reptile(w,s,t,n,p,deep) {}
    void MakeSound()const override
    {
        cout << "Kva-kva-kva-kva-kva-kva-kva" << endl;
    }

};

void RollCall(Animal &animal)
{
    animal.MakeSound();
    animal.Move();
    animal.Print();
    cout << "___________________________" << endl;
}

int main()
{
    Frog frog(0.10, 16, "Reptile", "Crazy Frog", "Boloto", 0.5, 30);
  
    Duck duck(1,15,"Bird","Donald Duck","Lake",2);
   /* duck.MakeSound();
    duck.Move();
    duck.Print();*/

    Lion lion(190,75,"Predator","King Lion","Africa",114);
 /*   lion.MakeSound();
    lion.Move();
    lion.Print();*/
    cout << "----------------------" << endl;
    RollCall(duck);
    RollCall(lion);
    RollCall(frog);
    //Animal animal;
    //animal.Move();
    //animal.Print();
    //animal.MakeSound();
    
}

