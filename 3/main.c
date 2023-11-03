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

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы 
int dlinna = 0;


void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент 
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

void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Очередь пуста\n");
	}
	while (struc)
	{
		printf("Имя - %s \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Очередь пуста\n");
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

/* Удаление элемента по содержимому. */
void del(char* name)
{
	struct node* struc = head; 
	struct node* prev = NULL;
	int flag = 0;      

	if (head == NULL) 
	{
		printf("Очередь пуста\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // установливаем голову на следующий элемент
		free(struc);  // удаляем первый элемент
		printf("Элемент %s удален", name);
		struc = head; // устанавливаем указатель для продолжения поиска
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) 
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;         // выставляем индикатор
			if (struc->next)  
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				printf("Элемент %s удален", name);
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else			
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);	// удаляем  элемент
				printf("Элемент %s удален", name);
				return;
			}
		}
		else
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)				// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент %s не найден\n", name);
		return;
	}


}
int menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	char d[256], f[256];
	while (1) {
		printf("\n1. Добавить элемент в очередь\n");
		printf("2. Просмотр очереди\n");
		printf("3. Удалить элемент из очереди\n");
		printf("4. Найти элемент очереди\n");
		printf("5. Выход\n");
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
			printf("Введите название элемента\n");
			scanf("%s", d);
			del(d);
			break;
		case 4:
			system("cls");
			printf("Введите название элемента\n");
			scanf("%s", f);
			find(f);
			break;
		case 5:
			exit(1);
			break;
		}
	}
	return 0;
}

int main() {
	menu();
}