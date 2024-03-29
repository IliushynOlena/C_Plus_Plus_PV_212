#include <iostream>
using namespace std;
class Square;
class RectangleNew
{
private:
    int height;
    int width;
public:
    RectangleNew() :height(0), width(0) {}
    explicit RectangleNew(int value) :height(value), width(value) {}
    RectangleNew(int height, int width) :height(height), width(width) {}
    void Print()const
    {
        cout << "Height :" << height << " ";
        cout << "Width :" << width << endl;
    }
    //operator typename() {}//1
    //operator typename()const {}//2
    //explicit operator typename()const {}//1
     explicit operator int()
    {
        return height * width;
    }
     explicit operator Square();
     
};



class Square
{
    int side;
public:
    Square():side(0){}
    Square(int s):side(s){}
    void Print()const
    {
        cout << "Side :" << side << " ";
        cout << "Side :" << side << endl;
    }
     operator RectangleNew()
    {
        RectangleNew rect(side, side+10);
        return rect;
    }
};


RectangleNew::operator Square()
{
    return Square(height + width);
}
int main()
{
    RectangleNew rect1(100);//parametrized ctor
    //Rectangle rect2 = 1000;

    int value = 9;
    double valDouble = value;//9.00000000000 -> int - double // standart to standart
    int a = (int)3.33;// standart to standart
    RectangleNew rect(10, 15);// standart to abstract
    Square sq(7);// standart to abstract
    rect.Print();
    sq.Print();
   

    value = (int) rect;//abstract to standart 
    cout << "Rect : " << value << endl;

    rect = sq;
    rect.Print();

    sq = (Square) rect;
    sq.Print();
}

