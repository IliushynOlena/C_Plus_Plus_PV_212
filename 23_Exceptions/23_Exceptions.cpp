#include <iostream>
#include <exception>
using namespace std;

class List
{
private:
    int size;
public:
	List() :size(0) {}
	List(int size) :size(size) {}

	int GetFromPosition(int pos)
	{
		if (size == 0) return 1;
		if (pos < 1 || pos > size) return 2;

		return rand() % 10;//0 1 2 3 4 5 6 7 8 9
	}	
};

float Divide(float a, float b)
{
	float res = 0;
	//exception ex("You can't divide by zero. You need to study math!!!");

	if (b == 0)
	{
		throw exception("You can't divide by zero. You need to study math!!!");
		//throw ex;
		//cout << "You can't divide by zero. You need to study math!!!" << endl;
		//return 0;//break
	}
	if (b == 1)
	{
		throw 404;
	}
	if (b == 5)
	{
		throw "You can't divide by zero. You need to study math!!!";
	}
	if (b == 10)
	{
		throw 'A';
	}
	
		res = a / b;
		cout << "Result [ " << res << "]" << endl;
		return res;

}

class PasswordInvalidException: public exception
{
public:
	PasswordInvalidException(const char * message):exception(message){}
};
class PasswordIsSmallException : public exception
{
	int lenght;
public:
	PasswordIsSmallException(const char* message, int lenght) :lenght(lenght), 
		exception(message) {}
	void Message()const
	{
		cout << what() << endl;
		cout << "Actual lenght : " << lenght << endl;
	}

};
void Validation(const char* login, const char* password)
{
	if (strlen(password) < 6)
		throw PasswordIsSmallException("To small password", strlen(password)) ;
	if (!isalpha(password[0]) || !islower(password[0]))
		throw PasswordInvalidException("Password Invalid");
	if (!isalpha(login[0]) || !isupper(login[0]))
		throw exception("login Invalid");

	cout << "Loading......" << endl;
}

class MyArr
{
private:
	int* arr;
	int size;
public:
	MyArr(int size = 10):size(size)
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 20;
		}
	}
	~MyArr()
	{
		if (arr != nullptr)
			delete[]arr;
	}
	int operator[](int index)
	{
		if (index < 0 || index >= size)
			throw out_of_range("Index is less that 0 or more than size");
		else
			return arr[index];
	}
	void CheckLenght(int len)
	{
		if (len < 0)
			throw length_error("Some lenght error....");

		cout << "Lenght is valid" << endl;
	}

	void SetSize(int newSize)
	{
		if (newSize <= 0)
			throw invalid_argument("New size is less than 0");
		else
		{
			int* temp = new int[newSize];
			for (int i = 0; i < size && i < newSize; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			size = newSize;
		}
	}
	void Print()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	MyArr arr(8);
	arr.Print();

	try
	{
		cout << "Element : " << arr[2] << endl;
		cout << "Element : " << arr[100] << endl;

		//arr.CheckLenght(-10);
		//arr.SetSize(-7);
	}	
	catch (out_of_range ex)
	{
		cout << ex.what() << endl;
	}
	catch (invalid_argument ex)
	{
		cout << "Invalid argument" << endl;
		cout << ex.what() << endl;
	}
	catch (logic_error ex)
	{
		cout << "Logic error" << endl;
		cout << ex.what() << endl;
	}
	catch (exception ex)
	{
		cout << "Exception catch" << endl;
		cout << ex.what() << endl;
	}

	cout << "Countinue....." << endl;
	/*char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter login : "; cin >> login;
		cout << "Enter password : "; cin >> password;

		try
		{
			Validation(login, password);
		}
		catch (PasswordInvalidException ex)
		{
			cout << "Invalid .....do something...." << endl;
			cout << ex.what() << endl;
			cout << "You need to use A-Z, a-z, 0-9" << endl;
		}
		catch (PasswordIsSmallException ex)
		{
			cout << "To small....do something....." << endl; 
			ex.Message();
			cout << "Lenght must be more than 6 symbols" << endl;
		}
		catch (exception& ex)
		{
			cout << "General error...." << endl;
			cout << ex.what() << endl;
		}		
		catch (...)
		{
			cout <<"Unknown exception" << endl;
		}
		
	}*/

	/*float a, b;
	cout << "Enter a and b : ";
	cin >> a >> b;

	try
	{
		float res = Divide(a, b);
		cout << "Result in main : " << res << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
		cout << "error with divide 1...." << endl;
	}
	catch (const char * ex)
	{
		cout << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	cout << "Continue........" << endl;
	cout << "Continue........" << endl;
	cout << "Continue........" << endl;
	cout << "Continue........" << endl;
	cout << "Continue........" << endl;*/
	
}
