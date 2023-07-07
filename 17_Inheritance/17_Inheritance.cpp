#include <iostream>
using namespace std;

class Enemy
{
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy(string name) :name(name), health(maxHealth), strength(0) {}
    Enemy(string name, float s) :name(name), health(maxHealth), strength(s) {}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << "% "<< endl;
        cout << "Strength : " << strength << endl;
    }
    void DecreaseHealth(int value)
    {
        if (health - value < 0)
            health = 0;
        else
            health -= value;//1 - 10
    }
    bool IsAlive()const
    {
        return health > 0;
    }
};
//Inheritance
//class Child : [spetificator] Parent
class Dragon : public Enemy
{
    float fire;
public:
    Dragon() :fire(0), Enemy("Dragon") {}
    Dragon(string name, float s, float fire) :fire(fire), Enemy(name,s) {}
    void Fight(int damage)
    {
        cout << "Getting damage " << damage << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after damage " << health << " % " << endl;
    }
    float Attack()
    {
        cout << "Attacking with strength " << strength << endl;
        return strength;
    }
    void Print()
    {
        cout << "-------- Dragon ----------" << endl;
        Enemy::Print();
        cout << "Fire " << fire << endl;
    }
};
class Monster : public Enemy
{
    float runSpeed;
public:
    Monster() :runSpeed(0), Enemy("Monster") {}
    Monster(string n, float s,float run) :runSpeed(run), Enemy(n,s) {}
    void Run()
    {
        cout << "Running with speed " << runSpeed << " km/h" << endl;
    }
    void Print()
    {
        cout << "-------- Monster ----------" << endl;
        Enemy::Print();
        cout << "runSpeed " << runSpeed << endl;
    }
};

int main()
{
    Monster monster("Petro", 1, 120);
    monster.Run();
    monster.Print();
    Dragon boss("Valera",5,3);//3 5
    Dragon dragon("Mayonez",4,3);
    boss.Print();
    dragon.Print();
    int i = 0;
    do
    {
        cout << "----------Round " << ++i << "---------------" << endl;
        boss.Fight(dragon.Attack());
        dragon.Fight(boss.Attack());

        boss.Print();
        dragon.Print();


    } while (boss.IsAlive()&& dragon.IsAlive());

   
    
}
