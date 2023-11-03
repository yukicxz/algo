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

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� 
int dlinna = 0;


void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������

struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� 
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
	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
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
		printf("������� �����\n");
	}
	while (struc)
	{
		printf("��� - %s \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* ����� �������� �� �����������. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("������� �����\n");
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

/* �������� �������� �� �����������. */
void del(char* name)
{
	struct node* struc = head; 
	struct node* prev = NULL;
	int flag = 0;      

	if (head == NULL) 
	{
		printf("������� �����\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		printf("������� %s ������", name);
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) 
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1;         // ���������� ���������
			if (struc->next)  
			{
				prev->next = struc->next; // ������ ���������
				free(struc);		    // �������  �������
				printf("������� %s ������", name);
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else			
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc);	// �������  �������
				printf("������� %s ������", name);
				return;
			}
		}
		else
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0)				// ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("������� %s �� ������\n", name);
		return;
	}


}
int menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	char d[256], f[256];
	while (1) {
		printf("\n1. �������� ������� � �������\n");
		printf("2. �������� �������\n");
		printf("3. ������� ������� �� �������\n");
		printf("4. ����� ������� �������\n");
		printf("5. �����\n");
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
			printf("������� �������� ��������\n");
			scanf("%s", d);
			del(d);
			break;
		case 4:
			system("cls");
			printf("������� �������� ��������\n");
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