#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
int menu() {
    int n = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    while (1) {
        printf("\n�������� ��������:\n");
        printf("1. �������\n");
        printf("2. �����\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������� ������ ������� ���������: ");
            scanf("%d", &n);
            smej(n);
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("�������� �����.\n");
        }
    }
    return 0;
}
int smej(int n) {
    // �������� � ���������� ������� ���������
    int** A;
    int count = 0;
    srand(time(NULL));
	A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		A[i] = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			A[i][j] = rand() % 2;
			A[j][i] = A[i][j];
			if (i == j) A[i][j] = 0;
			if (A[i][j] == 1) count++;
		}
    // ����� ������� ���������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    //����� ������������, ������������� � �������� ������
    printf("������ �����: %d\n", count);
    int* st;
    st = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) st[i]++;
        }
    for (int i = 0; i < n; i++) {
        if (st[i] == (n - 1))
            printf("������������ ������� #%d\n", i);
        if (st[i] == 0)
            printf("������������� ������� #%d\n", i);
        if (st[i] == 1)
            printf("�������� ������� #%d\n", i);
    }

    // �������� � ���������� ������� �������������
    int** B = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        B[i] = (int*)calloc(count, sizeof(int));
    }

    int reb = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] == 1) {
                B[i][reb] = 1;
                B[j][reb] = 1;
                reb++;
            }
        }
    }

    // ����� ������� �������������
    printf("\n������� �������������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    int gs = 0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            if (B[j][i] == 1) {
                gs++;
                break;
            }
        }
    }
    printf("������ ����� �� ������� �������������: %d\n", gs);
    //����� ������������, ������������� � �������� ������
    int* s;
    s = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count; j++) {
            if (B[i][j] == 1) s[i]++;
        }
    for (int i = 0; i < n; i++) {
        if (s[i] == gs)
            printf("������������ ������� #%d\n", i);
        if (s[i] == 0)
            printf("������������� ������� #%d\n", i);
        if (s[i] == 1)
            printf("�������� ������� #%d\n", i);
    }
    // ������������ ������
    for (int i = 0; i < n; i++) 
        free(B[i]);
    free(B);

    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);
}

int main() {
    menu();
}