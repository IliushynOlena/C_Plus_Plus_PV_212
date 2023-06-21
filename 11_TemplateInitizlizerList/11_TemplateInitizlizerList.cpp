#include <iostream>
using namespace std;
/*
int GetMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
long GetMax(long* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
short GetMax(short* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
*/
template<typename T_arr>
T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template<class T_coll, class T_val>
class MyClass
{
	int size;
	T_coll* collection;
	T_val point;
public:
	MyClass()
	{
		size = 0;
		collection = nullptr;
		//point = 0;
	}
	MyClass(T_coll*coll, T_val value):collection(coll),point(value){}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void SetCollection(T_coll* coll)
	{
		collection = coll;
	}
	void SetPoint(T_val value);
	void Print();	
};
template<typename T_coord>
class Point
{
	T_coord x;
	T_coord y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(T_coord value)
	{
		x = y = value;
	}
	Point(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void SetCoords(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
};
template<typename T_X, typename T_Y>
class NewPoint
{
	T_X x;
	T_Y y;
public:
	NewPoint()
	{
		x = y = 0;
	}
	NewPoint(T_X value)
	{
		x = y = value;
	}
	NewPoint(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
	void SetCoords(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << " Y: " << y << endl;
	}
};

class Array
{
	int* arr;
	int size;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	explicit Array(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const initializer_list<int> &list)
	{
		this->size = list.size();
		arr = new int[size];
		
		int i = 0;
	/*	for (int i = 0; i < size; i++)
		{
			arr[i] = list[i];
		}*/
		for (int element : list)//i = 0, i < size; i++
		{
			arr[i++] = element;
		}

	}
	void Fill(const initializer_list<int>& list)
	{
		if (arr != nullptr)delete[]arr;
		this->size = list.size();
		arr = new int[size];

		int i = 0;
		for (int element : list)//i = 0, i < size; i++
		{
			arr[i++] = element;
		}
	}
	void Print()const
	{
		cout << "Array size " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};


int main()
{
	int static_arr[5] { 1,2,3,4,5 };
	int *dynam_arr = new int [5] { 1, 2, 3, 4, 5 };

	Array arr;//default ctor
	arr.Print();

	Array arr2 (7);//parametrized ctor
	//Array arr2 = 7;//int -> Array
	arr2.Print();

	Array arr3({ 21, 4, 5, 6, 9, 8, 7, 22, 33, 44, 55, 66, 44,1,23,4,5,6,7,8,9,10 });
	arr3.Print();
	arr3.Fill({ 99,98,97,96,95 });
	arr3.Print();

	delete[]dynam_arr;

	/*Point<int> p1(10, 15);
	p1.Print();
	p1.SetCoords(33, 44);
	p1.Print();

	Point<float> p2(0.325, 0.145);
	p2.Print();

	NewPoint<int,float> p3(10, 0.145);
	p3.Print();
	p3.SetCoords(33, 44);
	p3.Print();*/

	/*long* long_arr = new long[4];
	for (int i = 0; i < 4; i++)
	{
		long_arr[i] = i + 1; 
		cout << long_arr[i] << " ";
	}
	cout << endl;

	char* char_arr = new char[4];
	for (int i = 0; i < 4; i++)
	{
		char_arr[i] = 'a' + i;
		cout << char_arr[i] << " ";
	}
	cout << endl;

	MyClass<long,string> cl1(long_arr, "Class with long arr");
	MyClass<char, string> cl2(char_arr, "Class with char arr");

	cl1.Print();
	cl2.Print();*/

	//delete[]long_arr;
	//delete[]char_arr;


	/*const int size = 10;
	int numbers1[size] = { 1,2,3,4,55,14,78,123,47,96 };
	cout << "Max int : " << GetMax(numbers1, size) << endl;
	long numbers2[size] = { 1,2,3,4,55,14,78,123,47,96 };
	cout << "Max int : " << GetMax(numbers2, size) << endl;
	short numbers3[size] = { 1,2,3,4,55,14,78,123,47,96 };
	cout << "Max int : " << GetMax(numbers3, size) << endl;
	float numbers4[size] = { 1,2,3,4,55,14,78,123.565,47,96 };
	cout << "Max int : " << GetMax(numbers4, size) << endl;
	double numbers5[size] = { 1,2,3,4,55,14,78,12,47,96.4645 };
	cout << "Max int : " << GetMax(numbers5, size) << endl;*/



}



template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::Print()
{
	cout << "Collection " << collection << endl;
	cout << "Value " << point << endl;
}

template<class T_coll, class T_val>
void MyClass<T_coll, T_val>::SetPoint(T_val value)
{
	point = value;
}