#include <iostream>
using namespace std;

int foo()
{
    return 2;
}

int A = 2;
int& Foo()
{
    
    return A;
}
class A
{
public:
    virtual string getName()
    {
        return "A";
    }
};
class B final: public A
{
public:
    virtual string getName() override final
    {
        return "B";
    }
};
//class C :public B
//{
//public:
//    //final
//   /* virtual string getName() override
//    {
//        return "C";
//    }*/
//};
class FriendClass
{
    //some
};
class SomeClass
{
    FriendClass f;
    //some code
    friend FriendClass;
};
class MyRectangle;
class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int pX, int pY) :x(pX), y(pY) {}
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void Show()const
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    friend MyRectangle;
};
class MyRectangle
{
    Point leftUpCorner;
    Point rightDownCorner;
public:
    MyRectangle() = default;
    MyRectangle(Point leftCorner, int sideA, int sideB) :leftUpCorner(leftCorner)
    {
        rightDownCorner = Point(leftUpCorner.x + sideA, leftUpCorner.y + sideB);
        //rightDownCorner = Point(leftUpCorner.GetX() + sideA, leftUpCorner.GetY() + sideB);
    }
    int getSideA()
    {
        return this->rightDownCorner.x - this->leftUpCorner.x;
    }
    int getSideB()
    {
        return this->rightDownCorner.y - this->leftUpCorner.y;
    }
    void Show()
    {
        leftUpCorner.Show();
        rightDownCorner.Show();
    }

};

class Image
{
public:
    class Pixel
    {
    private:
        int r, g, b;
    public:
        Pixel(int r, int g, int b) :r(r), g(g), b(b) {}
        void ShowInfo()
        {
            cout << "Pixels : r = " << r << " g = " << g << " b = " << b << endl;
        }
    };
private:
    static const int lenght = 5;
    Pixel pixels[lenght]{
        Pixel(0,25,47),
        Pixel(255,147,12),
        Pixel(23,25,147),
        Pixel(200,225,25),
        Pixel(5,80,32)
    };
public:
    void GetImageInfo()
    {
        for (int i = 0; i < lenght; i++)
        {
            pixels[i].ShowInfo();
        }
    }

};
int main()
{
    Image img;
    img.GetImageInfo();
    cout << "-------------------------" << endl;
   Image::Pixel pixel(255, 255, 255);
   pixel.ShowInfo();


    cout << foo() << endl;
    cout << A <<  endl;
    Foo() = 33;
    cout << A <<  endl;
    //foo() = 33;

    cout << foo() << endl;

    int var;
    var = 4;
    //4 = var;//Error
    //(var + 1) = 4;//Error

    int b = 10;
    int c = 20;
    int d = b + c;
    int e = 5 + 10;


}

