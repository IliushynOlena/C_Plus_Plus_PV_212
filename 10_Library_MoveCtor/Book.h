#pragma once
#include <iostream>
using namespace std;

//const int None = 0;
//const int Comedy = 1;
//const int History = 2;
//const int Drama = 3;
enum Genre
{
	None, Comedy, History, Drama, Horror, Science, Fantasy, Novel, Programming
};
class Book
{
private:
	string title;
	int year;
	string author;
	int pages;
	Genre genre;
public:
	Book();
	Book(string t, int y, string a, int p, Genre g):title(t),year(y),author(a),pages(p),genre(g){}
	void ShowInfo()const;




};

