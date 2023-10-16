#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
void xxx()
{
	setlocale(LC_ALL, "RUSSIAN");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i = 0, j = 0, r, elem_c, m, n;
	printf("������� ������ �������: ");
	scanf("%d", &m);
	n = m;
	int** a = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++)
		*(a + i) = (int*)malloc(sizeof(int*) * n);
	int** b = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++)
		*(b + i) = (int*)malloc(sizeof(int*) * n);
	int** c = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++)
		*(c + i) = (int*)malloc(sizeof(int*) * n);
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i < m)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100 + 1;
			j++;
		}
		j = 0;
		i++;
	}

	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;

	while (i < m)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		j = 0;
		i++;
	}
	time_t start1 = clock();//����� �� ����������
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < m; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	time_t stop = clock();//����� �� ����������
	double time2 = ((double) stop - (double) start1) / CLOCKS_PER_SEC;//����� ����������
	printf("����� ���������: %5.3f ������, ��������� ������� � ����", time2);
	FILE* res = fopen("umn.txt", "a");
	fprintf(res, "������� %dx%d ����������� �� %5.3f ������ \n", m, m, time2);
	fclose(res);
	for (i = 0; i < m; i++)
		free(a[i]);
	free(a);
	for (i = 0; i < m; i++)
		free(b[i]);
	free(b);
	for (i = 0; i < m; i++)
		free(c[i]);
	free(c);

	menu();
}

void file() {
	FILE* res;
	char str[50];
	res = fopen("umn.txt", "r");
	while (!feof(res)) {
		if (fgets(str, 48, res)) printf("%s", str);
	}
	fclose(res);
	menu();
}

int menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cc;
	printf("\n1. �������� �������\n");
	printf("2. ���������� ����������\n");
	printf("3. �����\n");
	scanf("%d", &cc);
	switch (cc) {
	case 1:
		xxx();
		break;
	case 2:
		file();
		break;
	case 3:
		_Exit(0);
		break;
	}
	return 0;
}

int main(){
	menu();
	return 0;
	}


//Slojnost' = O(n^3)

//Slojnost' = O(n^3)