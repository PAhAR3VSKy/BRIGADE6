#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>

struct medicine_list
{
	int cabinet_num;
	char first_name[20];
	char second_name[20];
	char otchestvo[20];
	char profession[30];
	char work_days[7][10];
	char work_time[11];
	medicine_list *next;
};

void print_medicine_list(medicine_list *head)
{
	medicine_list *p = head;
	puts("\n Вывод списка кабинетов и медицинского персонала\n");
	if (p == NULL) puts("Список пуст!");
	else
		while (p != NULL)
		{
			printf("Номер кабинета: %d\n", p->cabinet_num);
			printf("ФИО: %c %c %c\n", p->second_name, p->first_name, p->otchestvo);
			printf("Должность: %c\n", p->profession);
			printf("Рабочие дни: %c\n", p->work_days);
			printf("Часы работы: %c\n", p->work_time);
			p = p->next;
		}
	_getch();
}

struct patient_list
{
	int patient_num;
	char first_name[20];
	char second_name[20];
	char otchestvo[20];
	int med_cab_visiting;
	char visit_day[10];
	char visit_time[5];
	patient_list *next;
};

void print_patient_list(patient_list *head)
{
	patient_list *p = head;
	puts("\n PRINT LIST");
	if (p == NULL) puts("List empty!");
	else
		while (p != NULL)
		{
			printf("Номер пациента: %d\n", p->patient_num);
			printf("ФИО: %c %c %c\n", p->second_name, p->first_name, p->otchestvo);
			printf("Запись в кабинет номер %d\n", p->med_cab_visiting);
			printf("День записи: %c\n", p->visit_day);
			printf("Время записи: %c\n", p->visit_time);
			p = p->next;
		}
	_getch();
}

void medicine_menu()
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

void patient_menu()
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

	FILE *medicine; // файл мед кабинетов и мед персонала 
	FILE *patient; // файл мед кабинетов и мед персонала 

	medicine = fopen("medicine.txt", "r+");
	if ((medicine = fopen("medicine.txt", "r+")) == NULL)
		medicine = fopen("medicine.txt", "w+");
	patient = fopen("patient.txt", "r+");
	if ((patient = fopen("patient.txt", "r+")) == NULL)
		medicine = fopen("patient.txt", "w+");

	int key;
	int flag = 1;

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
			medicine_menu();
			break;
		}
		case 2:
		{
			patient_menu();
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
	fclose(patient);
	return 0;
}
