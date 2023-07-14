#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
protected:
    string brand;
    string model;
    int year;
    int mileage;
    string country;
    int max_speed;
    float volume;
public:
    Car() :brand(""), model(""), year(0), mileage(0), country(""), max_speed(0), volume(0) {}
    Car(string b, string m,int y, int mil,string c,  float v) :
        brand(b), model(m), year(y), mileage(mil), country(c), max_speed(0), volume(v) {}

    void setSpeed(int speed)
    {
        if(speed > 0)
            max_speed = speed;
    }
    virtual void Drive()const
    {
        cout << "I am a Car. I can drive with speed " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "----------- Car ---------------" << endl;
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
        cout << "Meliage : " << mileage << endl;
        cout << "Country : " << country << endl;
        cout << "Max speed : " << max_speed << endl;
        cout << "Volume : " << volume << endl;
    }
};
class PoliceCar : public Car
{
    int soundVolume;
public:
    PoliceCar() :soundVolume(0), Car() {}
    PoliceCar(string b, string m, int y, int mil, string c, float v,int sound) :
        soundVolume(sound), Car(b,m,y,mil,c,v) {}
     void Drive()const override
    {
        cout << "I am a Police Car. I can drive with speed " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "----------- Police Car ---------------" << endl;
        Car::Print();
        cout << "Sound Volume : " << soundVolume << endl;
    }
    void BeepBeep()
    {
        Beep(659.26, 200);
        Beep(659.26, 200);
        Sleep(200);
        Beep(659.26, 200);
        Sleep(100);
        Beep(523.26, 200);
        Beep(659.26, 200);
        Sleep(200);
        Beep(783.98, 200);
        Sleep(400);
        Beep(391.99, 200);
    }
};

class SportCar : public Car
{
    int nitro;
public:
    SportCar() :nitro(0), Car() {}
    SportCar(string b, string m, int y, int mil, string c, float v, int n) :
        nitro(n), Car(b, m, y, mil, c, v) {}
    void Drive()const override
    {
        cout << "I am a Sport Car. I can drive with speed " << max_speed << " km/h" << endl;
    }
    void Print()const
    {
        cout << "----------- Police Car ---------------" << endl;
        Car::Print();
        cout << "Nitro speed : " << nitro << endl;
    }
    void NitroSpeed()
    {
        cout << "I have nitro speed " << nitro << " km/h" << endl;
        max_speed += nitro;
        cout << "--------------> " << max_speed << endl;
   }
};

void TestDrive(Car &car)
{
    car.setSpeed(70);
    car.Drive();

}

int main()
{

    Car simpleCar("Fiat", "Doble", 2000, 300000, "Italy", 2.0);
    simpleCar.setSpeed(185);
    simpleCar.Drive();
    simpleCar.Print();

    PoliceCar policeCar("Toyota","Camry",2015,30000,"Japan",3.5,500);
    policeCar.setSpeed(215);
    policeCar.Drive();
    policeCar.Print();
    //policeCar.BeepBeep();

    SportCar sportCar("Lamborghini", "URUS", 2023, 20, "Italy", 4.0, 50);
    sportCar.setSpeed(250);

    TestDrive(policeCar);
    TestDrive(simpleCar);
    TestDrive(sportCar);
   
}

