
#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Dictionary
{
	string name;
	map<string, list<string>> words;
public:
	Dictionary(string name) :name(name) {}
	void PrintDictionary()
	{
		cout << "Dictionary : " << name << endl;
		for (auto pair : words)
		{
			cout << pair.first << " - ";
			for (string t : pair.second)
			{
				cout << t << " , ";
			} 
			cout << endl;
		}
	}
	void AddNewWord(string word, initializer_list< string> translate)
	{
		words.insert(make_pair(word, list<string>(translate)));
	}
	bool IsExists(string word)
	{
		return words.find(word) != words.end();
	}
	void AddTranslation(string word, string traslation)
	{
		words[word].push_back(traslation);
	}
};
int main()
{
	Dictionary dic("English-Ukrainian");

	dic.AddNewWord("run", { "bigtu", "zapochatkyvatu", "pochatu" });
	dic.AddNewWord("mind", { "dumka", "dusha", "svidomist", "sens" });
	dic.AddNewWord("bad", { "luxo", "poganuy", "borg", "deficit" });
	dic.PrintDictionary();

	//////////////////// add translate
	string input = "";//run
	cout << "Enter word to add translatins: "; getline(cin, input);

	if (!dic.IsExists(input))
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: ";
			getline(cin, translate);
			if (!translate.empty())
				dic.AddTranslation(input, translate);

		} while (!translate.empty());
	}
	dic.PrintDictionary();
	/*
	setlocale(LC_CTYPE, "ukr");

	map<string, list<string>> dic;

	string word = "run";
	list<string> meanings = list<string>({ "bigtu", "zapochatkyvatu", "pochatu" });
	dic.insert(make_pair(word, meanings));

	dic.insert(make_pair("mind", list<string>({ "dumka", "dusha", "svidomist", "sens" })));
	dic.insert(make_pair("bad", list<string>({ "luxo", "poganuy", "borg", "deficit" })));
	dic.insert(make_pair("test", list<string>({ "mean1", "mean2", "mean3" })));

	for (string s : dic["mind"])
	{
		cout << s << " ";
	}
	
	//////////////////// add translate
	string input = "";//run
	cout << "Enter word to add translatins: "; getline(cin, input);

	if (dic.find(input) == dic.end())
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: ";
			getline(cin, translate);
			dic[input].push_back(translate);

		} while (!translate.empty());
	}
	for (string s : dic[input])
	{
		cout << s << " ";
	}
	
	////////////////////// check translate
	cout << "Enter word to translate: "; getline(cin, input);

	if (dic.find(input) == dic.end())
		cout << "Translate not found!\n";
	else
	{
		cout << "\tMeans:\n";
		for (string elem : dic[input])
			cout << elem << " ";
	}
	*/

}
