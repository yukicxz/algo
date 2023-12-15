#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<queue>
#include<time.h>
#include<iostream>
using namespace std;
int BFSD(int** A, int* dist, int n, int v, int* distm, int* exc) {
    queue<int> q;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if ((A[v][i] > 0)  && (dist[i] ==-1)) {
                q.push(i);
                dist[i] = dist[v] + A[v][i];
                if ((distm[i] > dist[i]) && (dist[i] != 0))
                    distm[i] = dist[i];

            }
        }
    }
    return 0;
}

int oper(int** A, int* dist, int n, int v, int* distm, int* exc) {
    int err, d = -1, d1 = -1, r = 100000, r1 = 100000;
    printf("\n");
    for (v = 0; v < n; v++) {
        printf("���������� �� ������� %d\n ", v);
        BFSD(A, dist, n, v, distm, exc);
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1)
                printf("��� ����� ");
            else
                printf("%d ", dist[i]);
            if ((exc[v] < dist[i]) && (dist[i] != 0))
                exc[v] = dist[i];
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            dist[i] = -1;
        }
    }
    printf("\n���������� ����������:\n");
    for (int i = 0; i < n; i++) {
        if(distm[i]==10000)
            printf("��� ");
        else
        printf("%d ", distm[i]);
    }
    printf("\n");
    printf("\n���������������:\n");
    for (int i = 0; i < n; i++) {
        if(exc[i]!=-1)
        printf("%d ", exc[i]);
        else
            printf("���");
    }
    printf("\n\n");
    //����������� �������� � ������������ �������
    for (int i = 0; i < n; i++) {
        if (d < exc[i])
            d = exc[i];
    }
    if (d != -1) {
        printf("������� = %d\n", d);
        for (int i = 0; i < n; i++) {
            if (d == exc[i])
                printf("������������ ������� - %d\n", i);
        }
    }
    else
        printf("��� ��������");

    printf("\n");
    //����������� ������� � ����������� �������
    for (int j = 0; j < n; j++) {
        if ((r > exc[j]) && (exc[j] > 0))
            r = exc[j];
    }
    if (r != 100000) {
        printf("������ = %d\n", r);
        for (int j = 0; j < n; j++) {
            if (r == exc[j])
                printf("����������� ������� - %d\n", j);
        }
    }
    else 
        printf("��� �������");
    return 0;
}
int neorv(int** A, int* dist, int n, int v, int* distm, int* exc) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            A[i][j] = rand() % 6;
            A[j][i] = A[i][j];
            if (i == j) {
                A[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    oper(A, dist, n, v, distm, exc);
    return 0;
}

int neorn(int** A, int* dist, int n, int v, int* distm, int* exc) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            A[i][j] = rand() % 2;
            A[j][i] = A[i][j];
            if (i == j) {
                A[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    oper(A, dist, n, v, distm, exc);
    return 0;
}

int orv(int** A, int* dist, int n, int v, int* distm, int* exc) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           A[i][j] = rand() % 6;
            if (i == j) {
                A[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    oper(A, dist, n, v, distm, exc);
    return 0;
}

int orn(int** A, int* dist, int n, int v, int* distm, int* exc) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 2;
            if (i == j) {
                A[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    oper(A, dist, n, v, distm, exc);
    return 0;
}

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    int** A;
    int* dist;
    int* distm;
    int* exc;
    int v = 0, err;
    printf("������� ����� ���������� ������ ����� �������(������ ����): ");
    err = scanf("%d", &n);
    if ((err == 0) || (n <= 0)) {
        printf("������! ������� ����� ������\n");
        return 0;
    }
    dist = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
    }
    distm = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        distm[i] = 10000;
    }
    exc = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        exc[i] = -1;
    }
    srand(time(NULL));
    A = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(sizeof(int) * n);
    }
    if (argc > 1) {
        for (int i = 0; i < argc; ++i) {
            if (((strcmp(argv[i], "����������") == 0)|| (strcmp(argv[i], "�����������������") == 0))&& ((strcmp(argv[i+1], "����������") == 0) || (strcmp(argv[i+1], "�����������������") == 0))) {
                printf("����������������� ���������� ���� � \n");
                neorv(A, dist, n, v, distm, exc);
                return 0;
            }
            if (((strcmp(argv[i], "������������") == 0) || (strcmp(argv[i], "�����������������") == 0)) && ((strcmp(argv[i + 1], "������������") == 0) || (strcmp(argv[i + 1], "�����������������") == 0))) {
                printf("����������������� ������������ ���� � \n");
                neorn(A, dist, n, v, distm, exc);
                return 0;
            }
            if (((strcmp(argv[i], "����������") == 0) || (strcmp(argv[i], "���������������") == 0)) && ((strcmp(argv[i + 1], "����������") == 0) || (strcmp(argv[i + 1], "���������������") == 0))) {
                printf("��������������� ���������� ���� � \n");
                orv(A, dist, n, v, distm, exc);
                return 0;
            }
            if (((strcmp(argv[i], "������������") == 0) || (strcmp(argv[i], "���������������") == 0)) && ((strcmp(argv[i + 1], "������������") == 0) || (strcmp(argv[i + 1], "���������������") == 0))) {
                printf("��������������� ������������ ���� � \n");
                orn(A, dist, n, v, distm, exc);
                return 0;
            }
            //else {
            //    printf("������");
            //    return 0;
            //}
        }
    }
    else
        printf("������");
    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);
    free(dist);
    free(distm);
    free(exc);
    return 0;
}