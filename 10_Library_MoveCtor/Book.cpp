#include "Book.h"

Book::Book()
{
	title = "no title";
	year = 0;
	author = "no author";
	pages = 0;
	genre = None;

}

void Book::ShowInfo() const
{
	cout << "Title : " << title << endl;
	cout << "Year : " << year << endl;
	cout << "Author : " << author << endl;
	cout << "Pages : " << pages << endl;
	cout << "Genre : " << genre << " : ";	
	switch (genre)
	{
	case None:cout << "None" << endl;break;
	case Comedy:cout << "Comedy" << endl;break;
	case History:cout << "History" << endl;break;
	case Drama:cout << "Drama" << endl;break;
	case Horror:cout << "Horror" << endl;break;
	case Science:cout << "Science" << endl;break;
	case Fantasy:cout << "Fantasy" << endl;break;
	case Novel:cout << "Novel" << endl;	break;
	case Programming:cout << "Programming" << endl;	break;
	}

}
