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
	puts("\n ����� ������ ��������� � ������������ ���������\n");
	if (p == NULL) puts("������ ����!");
	else
		while (p != NULL)
		{
			printf("����� ��������: %d\n", p->cabinet_num);
			printf("���: %c %c %c\n", p->second_name, p->first_name, p->otchestvo);
			printf("���������: %c\n", p->profession);
			printf("������� ���: %c\n", p->work_days);
			printf("���� ������: %c\n", p->work_time);
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
			printf("����� ��������: %d\n", p->patient_num);
			printf("���: %c %c %c\n", p->second_name, p->first_name, p->otchestvo);
			printf("������ � ������� ����� %d\n", p->med_cab_visiting);
			printf("���� ������: %c\n", p->visit_day);
			printf("����� ������: %c\n", p->visit_time);
			p = p->next;
		}
	_getch();
}

void medicine_menu()
{
	
	int key;
	int flag = 1;

	while (flag) // ����� ������� � ����
	{
		system("cls");
		printf("���� ������ ��������� � ������������ ���������\n\n�������� ������ - 1\n�������� �������� ������ - 2\n��������������/�������� �������� ������ - 3\n����� � ������� ���� - 4\n");
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
			printf("����� � ������� ����...\n");
			break;
		}
		default:
		{
			printf("���������� ������ �� ����������, �������� ������!\n");
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

	while (flag) // ����� ������� � ����
	{
		system("cls");
		printf("���� ������ ��������� � ������ �� �����\n\n�������� ������ - 1\n�������� �������� ������ - 2\n��������������/�������� �������� ������ - 3\n����� � ������� ���� - 4\n");
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
			printf("����� � ������� ����...\n");
			break;
		}
		default:
		{
			printf("���������� ������ �� ����������, �������� ������!\n");
			break;
		}
		}
	}

	_getch();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	FILE *medicine; // ���� ��� ��������� � ��� ��������� 
	FILE *patient; // ���� ��� ��������� � ��� ��������� 

	medicine = fopen("medicine.txt", "r+");
	if ((medicine = fopen("medicine.txt", "r+")) == NULL)
		medicine = fopen("medicine.txt", "w+");
	patient = fopen("patient.txt", "r+");
	if ((patient = fopen("patient.txt", "r+")) == NULL)
		medicine = fopen("patient.txt", "w+");

	int key;
	int flag = 1;

	while (flag) // ����� ������� � ����
	{
		system("cls");
		printf("��������� ������������ ������������ ������\n\n������� ����\n\n");
		printf("������ �� ������� ��������� � ������������ ��������� - 1 \n������ �� ������� ��������� � ������ �� ����� - 2 \n���������� ������ - 3 \n");
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
			printf("���������� ������...\n");
			break;
		}
		default:
		{
			printf("���������� ������ �� ����������, �������� ������!\n");
			break;
		}
		}
	}

	_getch();
	fclose(medicine);
	fclose(patient);
	return 0;
}
