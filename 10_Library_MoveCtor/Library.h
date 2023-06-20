#pragma once
#include"Book.h"

class Library
{
private:
	string name;
	string address;
	Book* books;
	int countBooks;
public:
	Library();
	Library(string name, string address);
	Library(const Library& other);
	void Show()const;
	void AddNewBook(Book book);
	Library& operator =(const Library& other);
	Library(Library&& other);

	~Library()
	{
		if (books != nullptr)
			delete[]books;
	}

};

