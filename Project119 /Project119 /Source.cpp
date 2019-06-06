#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>

// Функции для кабинетов и мед персонала

struct medicine_list
{
	int cabinet_num;
	char first_name[20];
	char second_name[20];
	char otchestvo[20];
	char profession[30];
	int work_days[31] = { 0 };
	char work_time[11];
	medicine_list *next;
};

void print_medicine_element(medicine_list *head) // Вывод одного элемента списка
{
	printf("Номер кабинета: %d\n", head->cabinet_num);
	printf("ФИО: %s %s %s\n", head->second_name, head->first_name, head->otchestvo);
	printf("Должность: %s\n", head->profession);
	printf("Рабочие дни: %s\n", head->work_days);
	for (int i = 1; i < 32; i++)
	{
		if (head->work_days[i] != 0)
			printf("%d, ", i);
	}
	printf("\n");
	printf("Часы работы: %s\n\n", head->work_time);
}

void print_medicine_list(medicine_list *head) // Вывод полного списка
{
	medicine_list *p = head;

	system("cls");

	puts("\nВывод списка кабинетов и медицинского персонала\n");
	if (p == NULL) puts("Список пустой!");
	else
		while (p != NULL)
		{
			print_medicine_element(p);
			p = p->next;
		}

	_getch();
}

medicine_list *add_last(medicine_list *head, FILE *medicine) // Добавление нового элемента(врача) в конец списка
{
	medicine_list *q = new medicine_list, *p = head;

	system("cls");

	int day_key;

	printf("\nВведите номер кабинета: ");
	scanf("%d", &q->cabinet_num);
	printf("\nВведите ФИО через ENTER:\n");
	scanf("%s", &q->second_name);
	scanf("%s", &q->first_name);
	scanf("%s", &q->otchestvo);
	printf("\nВведите должность: ");
	scanf("%s", &q->profession);
	printf("\nВведите рабочие дни через ENTER, 0 - завершение ввода\n");
	while (1)
	{
		scanf("%d", &day_key);
		if (day_key)
			q->work_days[day_key] = 1;
		else
			break;
	}
	printf("\nВведите рабочие часы в формате ЧЧ:ММ-ЧЧ:ММ\n");
	scanf("%s", &q->work_time);

	q->next = NULL;

	// если список пуст
	if (!head)
		return q;
	// «идем в конец списка»
	while (p->next)
		p = p->next;
	p->next = q;
	return head;
}

// Функции пациентов и записи на прием

struct patient_list
{
	int patient_num;
	char first_name[20];
	char second_name[20];
	char otchestvo[20];
	int med_cab_visiting;
	int visit_day;
	char visit_time[5];
	patient_list *next;
};

void print_patient_element(patient_list *head) // Вывод одного элемента списка 
{
	printf("Номер пациента: %d\n", head->patient_num);
	printf("ФИО: %c %c %c\n", head->second_name, head->first_name, head->otchestvo);
	printf("Запись в кабинет номер: %d\n", head->med_cab_visiting);
	printf("День записи: %d\n", head->visit_day);
	printf("Время записи: %c\n", head->visit_time);
}

void print_patient_list(patient_list *head) // Вывод полного списка
{
	patient_list *p = head;

	system("cls");

	puts("\nВывод списка пациентов и записи не прием \n");
	if (p == NULL) puts("Список пустой!");
	else
		while (p != NULL)
		{
			print_patient_element(head);
			p = p->next;
		}

	_getch();
}

patient_list *add_last_patient(patient_list *head, FILE *medicine) // Добавление нового элемента(пациента) в конец списка
{
	patient_list *q = new patient_list, *p = head;

	system("cls");

	int day_key;

	printf("\nВведите номер пациента: ");
	scanf("%d", &q->patient_num);
	printf("\nВведите ФИО через ENTER:\n");
	scanf("%s", &q->second_name);
	scanf("%s", &q->first_name);
	scanf("%s", &q->otchestvo);

	q->next = NULL;

	// если список пуст
	if (!head)
		return q;
	// «идем в конец списка»
	while (p->next)
		p = p->next;
	p->next = q;
	return head;
}

void medicine_menu(FILE *medicine, medicine_list *med_list)
{

	int key;
	int flag = 1;

	while (flag) // Выбор пунктов в меню
	{
		system("cls");
		printf("Меню списка кабинетов и медицинского персонала\n\nПросмотр списка - 1\nПросмотр элемента списка - 2\nРедактирование/Удаление элемента списка - 3\nВыход в главное меню - 4\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			print_medicine_list(med_list);
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			med_list = add_last(med_list, medicine);
			break;
		}
		case 4:
		{
			flag = 0;
			printf("Выход в главное меню...\n");
			break;
		}
		default:
		{
			printf("Выбранного пункта не существует, выберите другой!\n");
			break;
		}
		}
	}

	_getch();
}

void patient_menu(FILE *medicine, FILE *patient, medicine_list *med_list, patient_list *patient_list)
{
	int key;
	int flag = 1;

	while (flag) // Выбор пунктов в меню
	{
		system("cls");
		printf("Меню списка пациентов и записи на прием\n\nПросмотр списка - 1\nПросмотр элемента списка - 2\nРедактирование/Удаление элемента списка - 3\nВыход в главное меню - 4\n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{
			flag = 0;
			printf("Выход в главное меню...\n");
			break;
		}
		default:
		{
			printf("Выбранного пункта не существует, выберите другой!\n");
			break;
		}
		}
	}

	_getch();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); // Подключение символов кириллицы для ввода и вывода в консоли

	medicine_list *med_list = NULL; // Список мед кабинетов и мед персонала
	patient_list *patient_list = NULL; // Список пациентов и записи на прием

	FILE *medicine; // файл мед кабинетов и мед персонала
	FILE *patient; // файл пациентов и записи на прием

	medicine = fopen("medicine.txt", "r+");
	if (medicine == NULL)
		medicine = fopen("medicine.txt", "w+");
	patient = fopen("patient.txt", "r+");
	if (patient == NULL)
		medicine = fopen("patient.txt", "w+"); // Создание файлов для списков

	int key; // Переменная выбора пункта меню
	int flag = 1; // флаг для выхода из цикла меню

	while (flag) // Выбор пунктов в меню
	{
		system("cls");
		printf("Программа РЕГИСТРАТУРА МЕДИЦИНСКОГО ЦЕНТРА\n\nГлавное меню\n\n");
		printf("Работа со списком кабинетов и медицинского персонала - 1 \nРабота со списком пациентов и записи на прием - 2 \nЗавершение работы - 3 \n");
		scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			medicine_menu(medicine, med_list);
			break;
		}
		case 2:
		{
			patient_menu(medicine, patient, med_list, patient_list);
			break;
		}
		case 3:
		{
			flag = 0;
			printf("Завершение работы...\n");
			break;
		}
		default:
		{
			printf("Выбранного пункта не существует, выберите другой!\n");
			break;
		}
		}
	}

	_getch();
	fclose(medicine);
	fclose(patient); // Закрытие файлов
	return 0;
}
