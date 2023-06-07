#include <iostream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

int Max(int a, int b)
{
    return a > b ? a : b;
}
float Max(float a, float b)
{
    return a > b ? a : b;
}
int Max(int a, int b, int c)
{
    return a > b ? a : b;
}

struct date
{
    int day;
    int month;
    int year;
};

class Student 
{
private:
    string name;
    string surname;
    string last_name;
    date birth_date;
    string phone;
    string city;
    string country;
    string education;
    string education_city;
    string education_country;
    int number_group;
    int* marks ;
    int markCount;
    float averageMark;
    void SetAverage()
    {
        float sum = 0;
        for (int i = 0; i < markCount; i++)
        {
            sum += marks[i];
        }averageMark =(float) sum / markCount;
    }
public:
    //ctor + TAB
    Student()
    {
        cout << "Constructor" << name << endl;
        //Ctrl + K + C
        //Ctrl + K + U
         name = "no name";
         surname = "no surname";
         last_name = "no last_name";
         birth_date = {0,0,0};
         phone = "no phone";
         city = "no city";
         country = "no country";
         education = "no education";
         education_city = "no education city";
         education_country = "no education country";
         number_group = 0;
         marks = nullptr;
         markCount = 0;
         averageMark = 0;

    }
    Student(string name)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;          
    }
    Student(string name, string lastname)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;
        this->last_name = lastname;
    }
    Student(string name, string lastname, int num)
    {
        cout << "Constructor invocation...." << endl;
        this->name = name;
        this->last_name = lastname;
        this->number_group = num;
    }
//#region
#pragma region Methods
    void setName(string name)
    {
       this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setLastname(string lastname)
    {
        this->last_name = lastname;
    }
    string getLastname()
    {
        return last_name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    string getSurname()
    {
        return surname;
    }
    void setBirthday(date d)
    {
        this->birth_date.day = d.day;
        this->birth_date.month = d.month;
        this->birth_date.year = d.year;
    }
    date getBirthday()
    {
        return birth_date;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    string getPhone()
    {
        return phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Last name : " << last_name << endl;
        cout << "Birthdate : " << birth_date.day<<"/"<<birth_date.month<<"/"<<birth_date.year << endl;
        cout << "Phone : " << phone << endl;
        cout << "City : " << city << endl;
        cout << "Country : " << country << endl;
        cout << "Education : " << education << endl;
        cout << "Education city : " << education_city << endl;
        cout << "Education country : " << education_country << endl;
        cout << "Number group : " << number_group << endl;
        cout << " Rating : ";
        for (int i = 0; i < markCount; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average Mark : " << averageMark << endl;

    }
    void Init()
    {
        cout << "Enter Name : "; cin>> name ;
        cout << "Enter Last name : "; cin >> last_name;
        cout << "Enter Birthdate : "; 
        cin >> birth_date.day;
        cin >> birth_date.month;
        cin >> birth_date.year ;
        cout << "Enter Phone : "; cin >> phone;
        cout << "Enter City : "; cin >> city ;
        cout << "Enter Country : "; cin >> country ;
        cout << "Enter Education : "; cin >> education ;
        cout << "Enter Education city : "; cin >> education_city;
        cout << "Enter Education country : "; cin >> education_country ;
        cout << "Enter Number group : "; cin >> number_group ;
    } 
    void AddMark(int mark)
    {
        //int* marks = nullptr;
        //int markCount = 0;
        markCount++;
        int* temp = new int[markCount];
        for (int i = 0; i < markCount-1; i++)
        {
            temp[i] = marks[i];
        }
        temp[markCount - 1] = mark;
        if (marks != nullptr)
            delete[]marks;
        marks = temp;
        SetAverage();
    }
    void Delete()
    {
        if (marks != nullptr)
            delete[]marks;
    }
    // ~ + TAB
    ~Student()
    {
        cout << "Destructor " << name << endl;
        Delete();
    }
#pragma endregion
};

int main()
{
    gotoxy(10, 10);
    Student st;//default c-tor
    st.setName("vasia");
    st.AddMark(12);
    st.AddMark(8);
    st.AddMark(6);
    st.AddMark(3);
    st.AddMark(11);
    st.AddMark(10);
    st.AddMark(4);
    //st.Init();
    st.Print();

    //st.setCity("Kyiv");
    //st.setPhone("+380678596458");
    //st.Print();
    Student st2;
    st2.setName("Ivan");

    Student student("Olena", "Iliushyn");
    student.Print();
    Student student2("Olena", "Iliushyn",123);
    student2.Print();
    
}

