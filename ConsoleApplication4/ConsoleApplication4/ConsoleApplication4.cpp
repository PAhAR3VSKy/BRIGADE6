#include"pch.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct btree
{
	int value;
	struct btree *left, *right;
} BinaryTree, *BinaryTreePtr;

// Включение вершины в дерево
void Ins_Btree(int val, btree **q)
{
	if (*q == NULL)
	{//Нашли место для добавления
		*q = new btree;
		(*q)->left = NULL;
		(*q)->right = NULL;
		(*q)->value = val;
		return;
	}
	if ((*q)->value > val)
		// Добавляем в левое поддерево
		Ins_Btree(val, &(*q)->left);
	else
		// Добавляем в правое поддерево
		Ins_Btree(val, &(*q)->right);
}

void Print_Btree(btree *p)
{
	if (p == NULL) return;
	Print_Btree(p->left);
	printf("%d", p->value);
	Print_Btree(p->right);
}

int maxDepth(BinaryTreePtr p)
{
	if (p == NULL)
		return 0;
	return fmax(maxDepth(p->left), maxDepth(p->right)) + 1;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int d, max;
	btree *root = NULL;
	printf("Нахождение максимальной глубины непустого дерева \n");

	printf("Введите дерево (0 для окончания ввода):\n");

	while (1)
	{
		scanf_s("%d", &d);
		if (d == 0)break;
		Ins_Btree(d, &root);
	}

	max = maxDepth(root);

	if (max == 0)
		printf("Дерево пустое!");
	else
		printf("Максимальная глубина: %d", max);

	_getch();
}