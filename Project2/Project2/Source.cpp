#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class StringOOP
{
private:
	int length;
	string word;
	/*string timeCreate;      
	string timeChange;*/
public:

	StringOOP()
	{
		word = "Пустая строка";
		length = 0;
	}

	StringOOP(string word)
	{
		this->word = word;
		this->length = word.length();
	}

	string GetWord()
	{
		return word;
	}

	int GetLength()
	{
		return length;
	}

	/*string GetTimeCreate()
	{
	return timeCreate;
	}
	string GetTimeChange()
	{
	return timeChange;
	}*/

	void SetWord(string word)
	{
		this->word = word;
	}

	void SetLength(int length)
	{
		this->length = length;
	}

	/*void SetTimeCreate(string timeCreate)
	{
	this->timeCreate = timeCreate;
	}
	void SetTimeChange(string timeChange)
	{
	this->timeChange = timeChange;
	}*/

	void Print()
	{
		cout << "Word: " << word << " Length: " << length << endl;
	}

	void FindWord(string litleWord)
	{
		if (word.find(litleWord) > word.length() || word.find(litleWord) < 0)
			cout << "Искомая часть подстроки отсутсвует в строке" << endl;
		else
			cout << "Искомая подстрока начинается с позиции: " << word.find(litleWord) << endl;
	}

	bool operator ==(const StringOOP & other)
	{
		return this->word == other.word;
	}

	bool operator !=(const StringOOP & other)
	{
		return !(this->word == other.word);
	}

	bool operator <(const StringOOP & other)
	{
		return this->word < other.word;
	}

	bool operator >(const StringOOP & other)
	{
		return this->word > other.word;
	}

	StringOOP & operator +(const StringOOP & other)
	{
		StringOOP temp;
		temp.word = this->word + other.word;
		return temp;
	}

	StringOOP & operator =(const StringOOP & other)
	{
		this->word = other.word;
		return *this;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	StringOOP a("Бан");
	StringOOP b("Лох");
	StringOOP c;
	c = a + b;
	c.Print();
	return 0;
}
