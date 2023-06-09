#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;//Victor
	int age;//15
	int* marks;//stack - 00x15HGT5
	int marksCount;//5

public:
	// Конструктор - метод, який викликається автоматично при створенні об'єкта класу.
	// Використовується для ініціалізації полів

	// Конструктора за замовчуванням (default ctor) - без параметрів
	Student()
	{
		name = "";
		age = 0;
		marks = nullptr;
		marksCount = 0;
	}

	// Параметризований конструктор - який приймає якісь параметри
	Student(string name, int age)
	{
		this->name = name;
		this->age = age;
		this->marks = nullptr;
		this->marksCount = 0;

		cout << "Paramerized Constructor [" << name << "]...\n";
	}
	Student(const Student &other)
	{
		this->name = other.name;
		this->age = other.age;
		//this->marks = other.marks;//error
		this->marks = new int[other.marksCount];
		for (int i = 0; i < other.marksCount; i++)
		{
			marks[i] = other.marks[i];
		}
		this->marksCount = other.marksCount;
	}
	
	// Деструктор - метод, який викликається автоматично при видаленні об'єкта класу
	// Використовується для очищення пам'яті, звільнення ресурсів і тд.
	~Student()
	{
		if (marks != nullptr)
			delete[] marks;
		cout << "Destructor [" << name << "]...\n";
	}


	void Print() const // константний метод, який не змінює властивості класа
	{
		cout << "-------- STUDENT [" << name << "] ---------\n";
		cout << "Age: " << age << endl;
		cout << "Marks: ";
		for (size_t i = 0; i < marksCount; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void AddMark(int value)
	{
		int* new_arr = new int[marksCount + 1];
		for (size_t i = 0; i < marksCount; ++i)
		{
			new_arr[i] = marks[i];
		}
		new_arr[marksCount] = value;
		if (marks != nullptr)
			delete[] marks;
		marks = new_arr;

		++marksCount;
	}

};


int main()
{

	Student testSt;					// виклик конструктора за замовчуванням
	Student st("Viktor", 15);	// виклик параметризованого конструктора

	st.AddMark(8);
	st.AddMark(7);
	st.AddMark(11);
	st.AddMark(10);


	st.Print();
	{
		Student st3 = Student(st);
		st3.Print();
	}
	st.Print();
} // виклик деструкторів