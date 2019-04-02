#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cstring>

const int N = 255;

struct btree
{
	long value;
	btree *l, *r;
};

// Открытие файла в заданном режиме
FILE *Open_file(const char *mode)
{
	char f_name[255];
	FILE *fp;
	printf("Введите имя текстового файла(с расширением):");
	gets_s(f_name);
	if ((fp = fopen(f_name, mode)) == NULL)
	{
		puts("Error creat!");
		getchar();
		exit(0);
	}
	return fp;
}

// Вывод строк файла на экран.
//Перед строкой отображается е?
//номер в файле
void Print_File(FILE * f)
{
	char str[N];
	rewind(f);
	while (feof(f) == 0)
	{
		fgets(str, N, f);
		printf("%s", str);
	}
}

void Ins_btree(FILE*f, btree **q, long n, char *str1)// Функция включения строки в дерево
{
	char str2[N];
	if (*q == NULL)
	{
		*q = new btree;
		(*q)->l = NULL;
		(*q)->r = NULL;
		(*q)->value = n;
		return;
	}
	fseek(f, (*q)->value, SEEK_SET);//позиционирует указатель в файле ставя его в начало строки
	fgets(str2, N, f);//считывает строку с текущего указателя
	if (strcmp(str2, str1) < 0)
		Ins_btree(f, &(*q)->r, n, str1);
	else
		Ins_btree(f, &(*q)->l, n, str1);
}

//Главная функция для добавления и сортировки в дерево
btree* text_to_btree(FILE*f, btree*q)
{
	long k = 0, tmp = 0;//адрес, изначально равен 0
	char s[N];
	fseek(f, tmp, SEEK_SET);//значение адреса текущего положения потока
	while (feof(f) == 0)
	{
		fseek(f, tmp, SEEK_SET);//значение адреса текущего положения потока, после включения в дерево
		fgets(s, N, f);//считывание строки
		if (feof(f) != 0) break;//выход из цикла, если конец файла
		k = ftell(f);//адрес после считывания строки
		Ins_btree(f, &q, tmp, s);//включение строки в дерево
		tmp = k;//адрес после включения строки в дерево
	}
	return q;
}

//Печать дерева
void Print_btree(FILE*f, btree *q, FILE *ptrFile)
{
	char s[N];
	if (q == NULL)
		return;
	Print_btree(f, q->l, ptrFile);
	fseek(f, q->value, 0);
	fgets(s, N, f);
	fputs(s, ptrFile); // печать строки в файл
	Print_btree(f, q->r, ptrFile);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Программа, для сортировки строк текста по алфавиту. \n");
	btree *root = NULL;
	FILE *ptrFile = fopen("result.txt", "wt"); // создание файла для записи результата
	FILE *fstream = Open_file("rt"); // открытие файла в заданном режиме
	printf("Текст в файле:\n");
	Print_File(fstream);
	root = text_to_btree(fstream, root);
	printf("\nОтсортированный текст помещен в файл result.txt\n");
	Print_btree(fstream, root, ptrFile);
	fclose(ptrFile);
	getchar();
}
