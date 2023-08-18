
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point() : x(0), y(0) {}
    //{
    //   /* this->x = 0;
    //    this->y = 0;*/
    //}
    Point(int x, int y) : x{ x }, y{ y } {}
    //{
    //    /*this->x = x;
    //    this->y = y;*/
    //}
    void Print()
    {
        cout << "X : " << x << " Y : " << y << endl;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
};
class RectangleNew
{
    Point leftUpCorner;//default 
    int width;
    int height;
public:
    RectangleNew(): width(0),height(0)
    {
        leftUpCorner.setX(0);
        leftUpCorner.setY(0);
        //width = 0;
        //height = 0;
        cout << "Default constructor" << endl;
    }
    RectangleNew(int x, int y, int w, int h):width(w), height(h)
    {
        leftUpCorner.setX(x);
        leftUpCorner.setY(y);
      /*  width = w;
        height = h;*/
        cout << "Parametrized constructor" << endl;
    }
    void Print()
    {
        leftUpCorner.Print();
        cout << "Height : " << height << endl;
        cout << "Width : " << width << endl;
    }
};
int main()
{
    RectangleNew r;
    r.Print();
    RectangleNew r2{ 5,5,25,14 };
    r2.Print();


    Point p;//default
    p.Print();
    Point p2(5, 7);//parametrized c-tor
    p2.Print();
    Point p3{ 11,12 };
    p3.Print();

    /*
    int a;//4 b
    int b = 10;
    int c = 3.33;

   // cout << a << endl;
    int arr[2];
    arr[0] += 2;
    cout << arr[0] << endl;
    cout << 5 << endl;
    int number = 5;// ініціалізація з копіюванням
    int value(42);// пряма ініціалізація
    int size{ 33};// уніфікована ініціалізація
    float PI{ 3.14 };
    cout << number << endl;
    cout << value << endl;
    cout << size << endl;
    cout << PI << endl;

    int answer{ 42 };
    const float goodTemp{ 36.6 };
    int grades[4]{ 11,10,5,7 };
    int mass[2][2]{ {1,2},{3,4} };

    int* pointer { nullptr };
    */
}

