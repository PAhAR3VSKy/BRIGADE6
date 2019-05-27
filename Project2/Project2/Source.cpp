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
	/*string timeCreate;      �������� ��� ��� �������!!
	string timeChange;*/
public:

	StringOOP()
	{
		word = "������ �����";
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
			cout << "����� ��������� � ������ �� ����������" << endl;
		else
			cout << "��������� ���������� � �������: " << word.find(litleWord) << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	StringOOP a("���");
	a.Print();
	a.FindWord("�");
	return 0;
}