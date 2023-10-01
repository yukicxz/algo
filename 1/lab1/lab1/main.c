#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
int zad1() {
	int max = 0, min = 100;
	int mas[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		mas[i] = 201 - 100;
		printf(" % d ", mas[i]);
		if (mas[i] > max)
			max = mas[i];
		if (mas[i] < min)
			min = mas[i];
	}
	printf("\n  %d", max - min);
	return 0;
}
int zad2() {
	int a[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 201 - 100;
		printf("%d ", a[i]);
	}
	return 0;
}
int zad3() {
	int size = 0;
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");
	printf("\n������� ������ ������� ");
	scanf("%d", &size);
	int* b = (int*)malloc(size * sizeof(int));
	if (b == NULL) {
		printf("\n������ ��������� ������");
		return 0;
	}
	for (int i = 0; i < size; i++) {
		b[i] = rand() % 100;
		printf("%d ", b[i]);
	}
	free(b);
	return 0;
}
int zad4() {
	srand(time(NULL));
	int c[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = rand() % 100;
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	for (int i = 0; i < 3; i++) {
		sum1 += c[i][0];
		sum2 += c[i][1];
		sum3 += c[i][2];
	}
	printf("\n%d %d %d", sum1, sum2, sum3);
	return 0;
}

int zad5() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0;
	int c = 1;
	struct cxz {
		char name[20];
		char sname[20];
		char facul[20];
		int nomer;
	} qwe[3];
	for (int i = 0; i < 3; i++) {
		printf("������� ���: ");
		scanf("%20s", qwe[i].name);

		printf("������� �������: ");
		scanf("%20s", qwe[i].sname);

		printf("������� �������� ����������: ");
		scanf("%20s", qwe[i].facul);

		printf("������� ��� ����� � �������: ");
		scanf("%d", &qwe[i].nomer);

		system("cls");
	}
	do {
		printf("��������, ��� �� ������ ����� (�� ���� �������� ������������): \n");
		printf("1. ����� ���������\n");
		printf("2. ������� ���������\n");
		printf("3. ���������� ���������\n");
		int choice;
		char poisk[20];
		char poisk2[20];
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("������� ��� ��������(��)\n");
			scanf("%20s", &poisk);
			for (int i = 0; i < 3; i++) {
				if (strcmp(qwe[i].name, poisk) == 0)
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);
			}

			break;
		case 2:
			printf("������� ������� ��������(��)\n");
			scanf("%20s", &poisk);
			for (int i = 0; i < 3; i++) {
				if (strcmp(qwe[i].sname, poisk) == 0)
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);
			}
			break;
		case 3:
			printf("������� ��������� ��������(��)\n");
			scanf("%20s", &poisk);
			for (int i = 0; i < 3; i++) {
				if (strcmp(qwe[i].facul, poisk) == 0)
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);
			}
			break;
		case 12:
			printf("������� ��� ��������(��)\n");
			scanf("%20s", &poisk);
			printf("������� ������� ��������(��)\n");
			scanf("%20s", &poisk2);
			for (int i = 0; i < 3; i++) {
				if ((strcmp(qwe[i].name, poisk) == 0) && (strcmp(qwe[i].sname, poisk2) == 0))
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);
			}
			break;
		case 23:
			printf("������� ������� ��������(��)\n");
			scanf("%20s", &poisk);
			printf("������� ��������� ��������(��)\n");
			scanf("%20s", &poisk2);
			for (int i = 0; i < 3; i++) {
				if ((strcmp(qwe[i].sname, poisk) == 0) && (strcmp(qwe[i].facul, poisk2) == 0))
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);

			}
			break;
		case 13:
			printf("������� ��� ��������(��)\n");
			scanf("%20s", &poisk);
			printf("������� ��������� ��������(��)\n");
			scanf("%20s", &poisk2);
			for (int i = 0; i < 3; i++) {
				if ((strcmp(qwe[i].name, poisk) == 0) && (strcmp(qwe[i].facul, poisk2) == 0))
					printf("������� %s %s ��������� �� ���������� %s, ����� �������� ������ %d\n", qwe[i].name, qwe[i].sname, qwe[i].facul, qwe[i].nomer);
			}
			break;

		}
		printf("������ ���������� �����?(1 - ��/2 - ���): ");
		scanf("%d", &c);
	} while (c == 1);

	return 0;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	printf("������� ����� ������� (1-5):\n");
	scanf("%d", &cc);
	switch (cc) {
	case 1:
		zad1();
		break;
	case 2:
		zad2();
		break;
	case 3:
		zad3();
		break;
	case 4:
		zad4();
		break;
	case 5:
		zad5();
		break;
	}
	return 0;
}

