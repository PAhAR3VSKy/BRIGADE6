// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

void EntMas(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " Элемент: ";
		cin >> arr[i];
	}
}

void OutMas(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void Merge(int *arr, int left, int mid, int right)
{
	OutMas(arr, right);
	cout << endl;
	int kLeft = 0;
	int kRight = 0;
	int *res = new int[right - left];
	while ((left + kLeft < mid) && (mid + kRight < right))
	{
		if (arr[left + kLeft] < arr[mid + kRight])
		{
			res[kLeft + kRight] = arr[left + kLeft];
			kLeft++;
		}
		else
		{
			res[kLeft + kRight] = arr[mid + kRight];
			kRight++;
		}
	}
	while (left + kLeft < mid)
	{
		res[kLeft + kRight] = arr[left + kLeft];
		kLeft++;
	}
	while (mid + kRight < right)
	{
		res[kLeft + kRight] = arr[mid + kRight];
		kRight++;
	}
	for (int i = 0; i < (kLeft + kRight); i++)
		arr[left + i] = res[i];
	delete[]res;
}

void MergeSort(int *arr, int left, int right)
{
	if (right <= left + 1)
		return;
	int mid = (left + right) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid, right);
	Merge(arr, left, mid, right);
}

int main()
{
	setlocale(LC_ALL, "ru");
	int *arr = new int[100], n;
	cout << "Введите размер массива: ";
	cin >> n;
	EntMas(arr, n);
	MergeSort(arr, 0, n);
	cout << "Результат:\n";
	OutMas(arr, n);

}