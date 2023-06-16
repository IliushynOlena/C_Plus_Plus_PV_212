#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        x = y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()const
    {
        cout << "X : " << x << " Y: " << y << endl;
    }
    Point Plus(const Point&other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }

    Point operator +(const Point& other)const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator +(int value)const
    {
        Point res(this->x + value, this->y + value);
        return res;
    }
    Point operator -(const Point& other)const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)const
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)const
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;//pointer - 00x15JKGJG
    }
    Point operator -()const
    {      
      /*  Point res(this->x*-1, this->y*-1);
        return res;*/
        return Point(-x, -y);
    }
    Point operator =(const Point& other)
    {
        this->x = other.x;//8....2
        this->y = other.y;//7....12
        return *this;
    }
    //bool operator <(const Point& other)const
    //{
    //   /* if ((this->x + this->y) < (other.x + other.y))
    //        return true;
    //    else
    //        return false;*/

    //    return (this->x + this->y) < (other.x + other.y);
    //}
    bool operator >(const Point& other)
    {
        return (this->x + this->y) > (other.x + other.y);
    }
    bool operator >=(const Point& other)
    {
        return (this->x + this->y) >= (other.x + other.y);
    }
    bool operator <=(const Point& other)
    {
        return (this->x + this->y) <= (other.x + other.y);
    }
    bool operator == (const Point& other)
    {
        return (this->x == other.x) && (this->y == other.y);
    }
    bool operator != (const Point& other)
    {
        //return (this->x != other.x) || (this->y != other.y);
        return !(*this == other);
    }

    Point operator++()//префіксна форма
    {
        ++this->x;
        ++this->y;
        return *this;
    }
    Point operator--()//префіксна форма
    {
        --this->x;
        --this->y;
        return *this;
    }
    Point operator++(int k)//постфіксна форма
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator--(int)//постфіксна форма
    {
        this->x--;
        this->y--;
        return *this;
    }
    int getX()const
    {
        return x;
    }
    int getY()const
    {
        return y;
    }
    friend bool operator <(const Point& point1, const Point& point2);
    friend ostream& operator<<(ostream& out, const Point& point);
    friend istream& operator>> (istream& in, const Point& point);
};

bool operator <(const Point& point1 ,const Point& point2)
{
    return (point1.x + point1.y) < (point2.x + point2.y);
}

ostream& operator<<(ostream& out, const Point& point)
{
    out << "New : X : " << point.x << " Y: " << point.y << endl;
    return out;
}
istream& operator>> (istream& in, const Point& point)
{
    in >> point.x;
    in.ignore(1);
    in >> point.y;
    return in;
}

//bool operator <(const Point& point1 ,const Point& point2)
//{
//    return (point1.getX() + point1.getY()) < (point2.getX() + point2.getY());
//}

int main()
{
    Point point1(10,5);
    Point point2(5,8);
    //int a = 5;
    //ostream cout;
    cout << "Enter new point";
    cin >> point1;//istream
    //cout << a << endl;
    cout << point1 << endl;//ostream
    cout << (point1 < point2) << endl;


    ++point1;
    --point2;
    point1--;
    point2++;
    cout << "Point 1 : "; point1.Print();
    cout << "Point 2 : "; point2.Print();
    cout << endl;


    if (point1 == point2)//point1.operator<(point2)
    {
        cout << "point 1 and point 2 is Equal" << endl;
    }
    else
    {
        cout << "point 1 and point 2 is not Equal" << endl;
    }

    if (point1 < point2)//point1.operator<(point2)
    {
        cout << "point 1 is smaller than point 2" << endl;
    }
    else
    {
        cout << "point 1 is not smaller than point 2" << endl;
    }
    if (point1 > point2)//point1.operator<(point2)
    {
        cout << "point 1 is bigger than point 2" << endl;
    }
    else
    {
        cout << "point 1 is not bigger than point 2" << endl;
    }




    int a = 5;
    int b = 7;
    cout << a + b << endl;
    Point res =  point1.Plus(point2);
    cout << "Point 1 : "; point1.Print();
    cout << "Point 2 : "; point2.Print();
    cout << "Res : "; res.Print();
    //point1 = point2;//<-
    res = point2 = point1;
    //res.operator=(point2.operator=(point1));
    cout << "----------------------" << endl;
    cout << "Point 1 : "; point1.Print();
    cout << "Point 2 : "; point2.Print();
    cout << "Res : "; res.Print();

    res = point1.Minus(point2);
    cout << "Res : "; res.Print();

    //res = point1.operator+(point2);
    res = point1 + point2;
    cout << "Res : "; res.Print();
    cout << "Point 2 : "; point2.Print();
    res = point2 + 50;
    cout << "Res : "; res.Print();

    res = point1 - point2;
    cout << "Res : "; res.Print();

    res = point1 * point2;
    cout << "Res : "; res.Print();

    res = point1 / point2;
    cout << "Res : "; res.Print();

    point1 += 15;
    cout << "Point 1 : "; point1.Print();
    //res =  point2.operator-();
    res = -point2;
    cout << "Res : "; res.Print();


}
