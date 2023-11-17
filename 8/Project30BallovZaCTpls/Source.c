#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
struct node
{
	int ver;  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка

struct node* get_struct(int v)
{
	struct node* p = NULL;

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}
	p->ver= v;
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(int d)
{
	struct node* p = NULL;
	p = get_struct(d);
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		last = p;
	}
	return;
}


/* Удаление элемента */
int del(void)
{
	struct node* struc = head;
	struct node* prev = NULL;
	if (isEmpty() == 0)
		return 0;
	prev = head->next;
	free(head);
	head = prev;
	return 0;
}
int isEmpty() {
	struct node* struc = head;
	if (head == NULL)
	{
		return 0;
	}
	return 1;
}
int BFS(int** A, int* vis, int n, int v) {
	spstore(v);
	vis[v] = 1;
	while (isEmpty() != 0) {
		struct node* struc = head;
		v = head->ver;
		printf("%d ", v);
		del();
		for (int i = 0; i < n; i++) {
			if (A[v][i] == 1 && vis[i] != 1) {
				spstore(i);
				vis[i] = 1;
			}
		}
	}
	return 0;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	int** A;
	int* vis;
	int v = 0;
	// Создание и заполнение матрицы смежности
	printf("Введите НОРМАЛЬНОЕ количество вершин графа: ");
	scanf("%d", &n);
	vis = (int*)calloc(n, sizeof(int));
	srand(time(NULL));
	A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			A[i][j] = rand() % 2;
			A[j][i] = A[i][j];
			if (i == j) {
				A[i][j] = 0;
			}
		}
	}

	// Вывод матрицы смежности
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Введите НОРМАЛЬНУЮ вершину, с которой хотите начать: ");
	scanf("%d", &v);
	time_t start1 = clock();
	BFS(A, vis, n, v);
	time_t stop = clock();
	double time2 = ((double)stop - (double)start1) / CLOCKS_PER_SEC;
	printf("\nВремя обхода: %5.3f секунд", time2);
}