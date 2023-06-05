#include <iostream>
using namespace std;
/*
struct Player
{
    string name;
    short age;
    int games;
    int goals;      
};

void PrintPlayer(Player& player)
{
    cout << "Name : " << player.name << endl;
    cout << "Age : " << player.age << endl;
    cout << "Games : " << player.games << endl;
    cout << "Goals : " << player.goals << endl;
}
void InitPlayer(Player& player)
{
    cout << "Name : ";
    cin >> player.name;
    cout << "Age : ";
    cin >> player.age;
    player.games = 0;
    player.goals = 0;
}
void AddGameToPlayer(Player& player, int goals = 0)
{
    ++player.games;
    player.goals += goals;
}
*/
class Player
{
private:
    string name;
    short age;
    int games;
    int goals;
public:
    void PrintPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void Initialize()
    {
        name = "no name";
        age = 0;
        games = 0;
        goals = 0;
    }
    void InitPlayerFromKeyboard()
    {
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
    }

    bool IsValidGoals(int goals)//5
    { 
        return goals >= 0;
      /*  if (goals > 0)
        {
            return true;
        }
        else
        {
            return false;
        }*/
    }
    void AddGame(int goals = 0)//-10 
    {
        ++games;
        if(IsValidGoals(goals))
            this->goals += goals;
        //goals += goals;
    }


};

class Student
{
private:
    string name;
    int marks[3];
public:
    double getAverage()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += marks[i];
        }
        return sum / 3;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setMark(int mark, int index)
    {
        if (mark < 1 or mark > 12)
            mark = 0;
        marks[index] = mark;
    }
    int getMark(int index)
    {
        return marks[index];
    }
};
int main()
{
    Student st;//object
    st.setName("Petro");
    st.setMark(10,0);
    st.setMark(7,1);
    st.setMark(8,2);

    cout << "Name : " << st.getName() << " Mark : " << st.getMark(0) << endl;
    cout << "Average mark : " << st.getAverage() << endl;


    /*
    Student st;//object
    st.name = "Petro";
    st.marks[0] = 10;
    st.marks[1] = 7;
    st.marks[2] = 8;
    cout << "Name : " << st.name << " Mark : " << st.marks[0] << endl;
    cout << "Average mark : " << st.getAverage() << endl;
    */

    /*
    Player player;
    player.Initialize();
    player.InitPlayerFromKeyboard();
    player.PrintPlayer();

    player.AddGame();
    player.AddGame(5);
    player.AddGame(1);
    player.PrintPlayer();
    */
    /*
    Player player;
    InitPlayer(player);
    PrintPlayer(player);

    AddGameToPlayer(player, 2);
    AddGameToPlayer(player);
    AddGameToPlayer(player,3);
    PrintPlayer(player);
    */    
}
