#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы стека


// Функции добавления элемента, просмотра стека
void spstore(void), review(void);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент стека
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите название объекта: \n");   // вводим данные
	scanf("%s", s);
	if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) 
	{
		p->next = last;
		last = p;
	}
	return;
}

/* Просмотр содержимого стека. */
void review(void)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		printf("Имя - %s \n", struc->inf);
		struc = struc->next;
	}
	return;
}

void review_head(void)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("Стек пуст\n");
	}
		printf("Имя - %s \n", struc->inf);
	return;
}
/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("Стек пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("Элемент %s найден", name);
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}

void del_head(void)
{
	struct node* struc = last;
	struct node* prev = NULL;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	prev = last->next;
	free(last);
	last = prev;
	printf("Элемент вершины стека успешно удален\n");
	return;
}
int menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	char d[256], f[256];
	while (1) {
		printf("\n1. Добавить элемент в стек\n");
		printf("2. Просмотр стека\n");
		printf("3. Удалить элемент из стека\n");
		printf("4. Найти элемент стека\n");
		printf("5. Просмотр вершины стека\n");
		printf("6. Выход\n");
		scanf("%d", &cc);
		switch (cc) {
		case 1:
			system("cls");
			spstore();
			break;
		case 2:
			system("cls");
			review();
			break;
		case 3:
			system("cls");
			del_head();
			break;
		case 4:
			system("cls");
			printf("Введите название элемента\n");
			scanf("%s", f);
			find(f);
			break;
		case 5:
			system("cls");
			review_head();
			break;
		case 6:
			exit(1);
			break;
		}
	}
	return 0;
}

int main() {
	menu();
}