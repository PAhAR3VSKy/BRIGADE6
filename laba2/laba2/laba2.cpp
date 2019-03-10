#include "pch.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define N 100

struct list
{
	int value;
	list *next;
};

// Удаление элемента из списка по значению
list* Del_value(int n, list *head)
{
	list *p = head, *t;
	if (head == NULL)
	{
		puts("LIST EMPTY!");
		return NULL;
	}

	// удаляем первый элемент
	if (head->value == n)
	{
		t = head;
		head = head->next;
		delete t;
		return head;
	}

	// ищем в списке значение
	while (p->next != NULL)
	{
		if (p->next->value == n)
		{
			t = p->next;
			p->next = p->next->next;
			delete t;
			return head;
		}
		else
			p = p->next;
	}
	puts("NO VALUE!");
	return head;
}

// Добавление элемента в конец списка
list *Add_last(list *head, int n)
{
	list *q = new list, *p = head;
	q->value = n;
	q->next = NULL;
	// если список пуст
	if (!head)
		return q;
	// «идем в конец списка»
	while (p->next) p = p->next;
	p->next = q;
	return head;
}

// Вывод списка
int Print_list(list *head)
{
	if (!head)
	{
		puts("The empty list");
		return 1;
	}
	while (head)
	{
		if (!head->next)
			printf("%d", head->value);
		else
			printf("%d->", head->value);
		head = head->next;
	}
	return 0;
}

// Создание списка
list *create_list()
{
	char str[N];
	list *first = NULL;
	puts("The lists creating. Please, enter the numbers:");
	while (1)
	{
		gets_s(str, N);
		if (str[0] == '\0')break;
		first = Add_last(first, atoi(str));
	}
	printf("Your list:\n");
	Print_list(first);
	return first;
}

// Удаление первого входжения повторяющихся элементов

int delete_same(list *&head)
{
	if (!head)
	{
		printf("%d", 0);
		return NULL;
	}
	list *q = head, *tmp = q->next;
	int k = 0;
	int count = 0;
	while (q->next)
	{
		k = 0;
		do
		{
			list *p = q->next;
			if (tmp->value == q->value)
			{
				head = Del_value(q->value, head);
				q = head;
				(count)++;
				k = 1;
			}
		} while (tmp = tmp->next);

		if (k == 0)
			q = q->next; // не было удалений в списке
		tmp = q->next;
	}
	return count;
}

int main()
{
	list *spisok;
	int count = 0;
	printf("This program deleting first same elements. \n");
	spisok = create_list();
	if (spisok == NULL)
		getchar();
	else {
		count = delete_same(spisok);
		printf("\nNumber of deleted elements: %d", count);
		printf("\n");
		printf("Result: \n");
		Print_list(spisok);
		getchar();
	}
	return 0;
}