#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

};

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;
		if (data > root->data) root->left = r;
		else root->right = r;
		return r;
	}
	if (data == r->data) {
		printf("Данное число уже есть в дереве\n");
		return root;
	}
	if (data > r->data)
		CreateTree(r, r->left, data);

	else
		CreateTree(r, r->right, data);
	return root;
}

struct Node* search(struct Node* root, int key) {
	if (root == NULL || root->data == key)
		return root;
	if (root->data < key)
		return search(root->right, key);
	return search(root->left, key);
}

void print_tree(struct Node* r, int l)
{
	if (r == NULL)
	{
		return;
	}
	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}
	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

int EnterCount(struct Node* root, int key) {
	if (root == NULL)
		return 0;
	int count = 0;
	if (root->data == key)
		count++;
	count += EnterCount(root->left, key);
	count += EnterCount(root->right, key);
	return count;
}

int main()
{
	struct Node* root = NULL;
	setlocale(LC_ALL, "");
	int start = 1;
	float D;
	int cnt = 1;
	int data;
	while (start)
	{
		printf("Введите ЦЕЛОЕ НОРМАЛЬНОЕ число: ");
		scanf_s("%f", &D);
		printf("Продолжить? 1-Да, 2-Нет: ");
		scanf_s("%d", &cnt);
		if (cnt == 2)
		{
			root = CreateTree(root, root, D);
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else if (cnt == 1)
			root = CreateTree(root, root, D);
		else
			printf("Ошибка!\n");
	}
	print_tree(root, 0);
	printf("Введите значение для поиска: ");
	scanf_s("%d", &data);
	struct Node* res = search(root, data);
	if (res != NULL)
		printf("Значение найдено: %d\n", res->data);
	else printf("Значение не найдено\n");
	int entries = EnterCount(root, data);
	printf("Число вхождений данного элемента в дерево: %d", entries);
	return 0;
}