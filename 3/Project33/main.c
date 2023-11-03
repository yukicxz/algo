#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

struct node* head = NULL, * last = NULL; // ��������� �� ������ � ��������� �������� �����


// ������� ���������� ��������, ��������� �����
void spstore(void), review(void);

char find_el[256];
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� �����
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
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

/* �������� ����������� �����. */
void review(void)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("���� ����\n");
	}
	while (struc)
	{
		printf("��� - %s \n", struc->inf);
		struc = struc->next;
	}
	return;
}

void review_head(void)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("���� ����\n");
	}
		printf("��� - %s \n", struc->inf);
	return;
}
/* ����� �������� �� �����������. */
struct node* find(char* name)
{
	struct node* struc = last;
	if (head == NULL)
	{
		printf("���� ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("������� %s ������", name);
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}

void del_head(void)
{
	struct node* struc = last;
	struct node* prev = NULL;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	prev = last->next;
	free(last);
	last = prev;
	printf("������� ������� ����� ������� ������\n");
	return;
}
int menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	char d[256], f[256];
	while (1) {
		printf("\n1. �������� ������� � ����\n");
		printf("2. �������� �����\n");
		printf("3. ������� ������� �� �����\n");
		printf("4. ����� ������� �����\n");
		printf("5. �������� ������� �����\n");
		printf("6. �����\n");
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
			printf("������� �������� ��������\n");
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