#include <iostream>
using namespace std;

class Date
{
private:
    const int baseYear;
    int& currentYear;
    int day;
    int month;
    int year;
public:
    Date(int currentYear):baseYear(2000), currentYear(currentYear),day(0),month(0),year(0) { }
    Date(int base, int currentYear):baseYear(base), currentYear(currentYear),day(0),month(0),year(0) { }
   /* Date(const Date &other)
    {

    }*/
    void setDay(int day)
    {
        this->day = day;
    }
   /* void setDay(Date * const this, int day)
    {
        this->day = day;
    }
    int getDay(Date* const this)const
    {
        return 5;
    }*/
    int getDay()
    {
        return day;
    }
    int getDay() const
    {
        return day;
    }    
    void Show()
    {
        cout << "Base Year : " << baseYear << endl;
        cout << "Current Year : " << currentYear << endl;
        cout << "Day : " << day << endl;
        cout << "Month : " << month << endl;
        cout << "Year : " << year << endl;
    }
};
class Account
{
private:
    double sum;
    const double rate;
    //const double PI = 3.1464654894;
public:
    Account(double sum, double rate):rate(rate)
    {
        this->sum = sum;
        //this->rate = rate;
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome()const
    {
        return sum *rate / 100;//2000*5/100;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};

void doSomething(long number) {}

float doSomething()
{
    return 1.04;//double -> float
}

class Array
{
    int size;
    int* arr;
public:
    explicit Array(int size  = 10)
    {
        this->size = size;
        arr = new int[size];       
    }
    explicit Array(const Array& other)
    {
        this->size = other.size;
        this->arr = new int[other.size];
        for (int i = 0; i < other.size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    ~Array()
    {
        delete[]arr;
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int index, int value)
    {
        arr[index] = value;
    }
    void Display(int index)const
    {
        cout << arr[index] << " ";
    }
};

void DisplayArr(const Array& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.Display(i);
    }

}
int main()
{
    int size = 4;
    Array arr(size);//ctor //explicit
    for (int i = 0; i < size; i++)
    {
        arr.setValue(i, size - i - 1);
    }
    DisplayArr(arr);
    cout << endl;
    cout << "!!!!!!!" << endl;
    //DisplayArr(3);//implicit
    //Array arr2 = arr;//ctor copy - error
    Array arr2(arr);//ctor copy
    DisplayArr(arr2);
    //Student st = 15;

    /*
    double a(10);//int -> double - 10.0000000000000
    cout << a << endl;
    a = 5;//int -> double
    doSomething(5);//int -> long

    double d = (int) 5.0 / 4;//int -> double


    Account account1(2000, 5);
    const Account account2(5000, 8);

    cout << "Rate 1 : " << account1.getRate() << endl;
    cout << "Rate 2 : " << account2.getRate() << endl;

    cout << "Summa 1 : " << account1.getSum() << endl;
    cout << "Summa 2 : " << account2.getSum() << endl;

    cout << "Income 1 : " << account1.getIncome() << endl;
    cout << "Income 2 : " << account2.getIncome() << endl;

    cout << "Set summa 1 : " << account1.setSum() << endl;*/
    //cout << "Set summa 2 : " << account2.setSum() << endl;

    /*
    int year = 2023;
    int base;
    cout << "Enter base year :";
    cin >> base;
    Date day(base, year);//default c-tor
    //day.setDay(10);
    //cout << "Date : " << day.getDay() << endl;
    day.Show();
    */
    /*
    const int size = 4;

    const string str{ "first day" };

    const char* filename{ "text.txt" };
    const int days[]{ 31,31,28 };
    //days[2] = 29;
    const Date date{ 15,6,2023 };
    //date.setDay(20); //error
    int day =  date.getDay();

    Date newDate{ 1,1,2001 };
    cout << "New day : " << newDate.getDay() << endl;
    */

  
    

}

